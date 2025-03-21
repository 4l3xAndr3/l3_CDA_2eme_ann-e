#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <float.h>
#include <unistd.h>

#define TAILLE_TAB 100000000
#define TAILLE_BLOCK 2048
#define NB_MESURE 10


double *A, *B, *C;
int nb_threads;
int method;
int allow_migration;

//farming
pthread_mutex_t lock;
int next_block = 0;

void * cyclique_elements(void *arg) {
    int thread_id = *(int *)+arg;
    for(int i=thread_id; i <TAILLE_TAB; i+=nb_threads){
        if(A[i]<B[i]){
           C[i]=A[i];
        }else{
           C[i]=B[i]; 
        }
    }
    return NULL;
}

void *cyclique_blocs_elements(void *arg) {
    int thread_id = *(int *)arg;

    for (int i = thread_id * TAILLE_BLOCK; i < TAILLE_TAB; i += nb_threads * TAILLE_BLOCK) {
        for (int j = 0; j < TAILLE_BLOCK && (i + j) < TAILLE_TAB; j++) {
            if (A[i + j] < B[i + j]) {
                C[i + j] = A[i + j];
            } else {
                C[i + j] = B[i + j];
            }
        }
    }
    return NULL;
}

void * farming(void *arg) {
    int thread_id = *(int *)arg;
    int local_blocks = 0;
    while(1){
        pthread_mutex_lock(&lock);
        int block_start = next_block * TAILLE_BLOCK;
        if (block_start >= TAILLE_TAB) {
            pthread_mutex_unlock(&lock);
            break;
        }
        next_block++;
        pthread_mutex_unlock(&lock);

        for (int i = 0; i < TAILLE_BLOCK && (block_start + i) < TAILLE_TAB; i++) {
            if(A[i+block_start]<B[i+block_start]){
                C[i+block_start]=A[i+block_start];
             }else{
                C[i+block_start]=B[i+block_start]; 
             }
        }
        local_blocks++;
    }
    return NULL;
    }

int main(int argc, char *argv[]) {
    if (argc < 4) {
        return 1;
    }
    method = atoi(argv[1]);
    nb_threads = atoi(argv[2]);
    allow_migration = atoi(argv[3]);

    A = (double *)malloc(TAILLE_TAB * sizeof(double));
    B = (double *)malloc(TAILLE_TAB * sizeof(double));
    C = (double *)malloc(TAILLE_TAB * sizeof(double));

    for (int i = 0; i < TAILLE_TAB; i++) {
        A[i] = rand() / (double)RAND_MAX;
        B[i] = rand() / (double)RAND_MAX;
    }

    pthread_t threads[nb_threads];
    int thread_ids[nb_threads];
    pthread_mutex_init(&lock, NULL);

    struct timespec start, end;
    double elapsed_time = 0;
    for (int t = 0; t < NUM_MEASUREMENTS; t++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        next_block = 0;
        for (int i = 0; i < nb_threads; i++) {
            thread_ids[i] = i;
            if (method == 1) {
                pthread_create(&threads[i], NULL, compute_min_cyclic, &thread_ids[i]);
            } else if (method == 2) {
                pthread_create(&threads[i], NULL, compute_min_block_cyclic, &thread_ids[i]);
            } else {
                pthread_create(&threads[i], NULL, compute_min_farming, &thread_ids[i]);
            }
        }
        for (int i = 0; i < num_threads; i++) {
            pthread_join(threads[i], NULL);
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed_time += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    }


    FILE *file =fopen("resultat.csv","w");
    const char *texte = method+ "," + threads + "," + migration + "," + EXEC_TIME;
    fwrite(texte, sizeof(char), size(texte), file);
    printf("Average execution time: %f seconds\n", elapsed_time / NUM_MEASUREMENTS);
    fclose(file);


    pthread_mutex_destroy(&lock);
    free(A);
    free(B);
    free(C);
    return 0;
}