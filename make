CC = gcc
CFLAGS = -Wall -Wextra -g

# Targets
all: test_sequence test_tab_dynamique

# Sequence
test_sequence: etape1/main.o etape1/sequence.o etape1/hash_x86_64.o etape1/list_x86_64.o
	$(CC) $(CFLAGS) etape1/main.o etape1/sequence.o etape1/hash_x86_64.o etape1/list_x86_64.o -o test_sequence

etape1/main.o: etape1/main.c etape1/sequence.h
	$(CC) $(CFLAGS) -c etape1/main.c -o etape1/main.o

etape1/sequence.o: etape1/sequence.c etape1/sequence.h
	$(CC) $(CFLAGS) -c etape1/sequence.c -o etape1/sequence.o

etape1/hash_x86_64.o: etape1/hash_x86_64.c
	$(CC) $(CFLAGS) -c etape1/hash_x86_64.c -o etape1/hash_x86_64.o

etape1/list_x86_64.o: etape1/list_x86_64.c
	$(CC) $(CFLAGS) -c etape1/list_x86_64.c -o etape1/list_x86_64.o

# Tab Dynamique
test_tab_dynamique: test_tab_dynamique.o etape2/tab_dynamique.o
	$(CC) $(CFLAGS) test_tab_dynamique.o etape2/tab_dynamique.o -o test_tab_dynamique

test_tab_dynamique.o: test_tab_dynamique.c etape2/tab_dynamique.h
	$(CC) $(CFLAGS) -c test_tab_dynamique.c -o test_tab_dynamique.o

etape2/tab_dynamique.o: etape2/tab_dynamique.c etape2/tab_dynamique.h
	$(CC) $(CFLAGS) -c etape2/tab_dynamique.c -o etape2/tab_dynamique.o

# Clean
clean:
	rm -f etape1/*.o etape2/*.o test_sequence test_tab_dynamique
