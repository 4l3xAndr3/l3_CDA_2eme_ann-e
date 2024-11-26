CC = gcc
CFLAGS = -Wall -Wextra -g

#sequence

test_sequence: etape1/main.c etape1/sequence.o
	$(CC) $(CFLAGS) -c etape1/sequence.o etape1/hash_x86_64.o etape1/list_x86_64.o etape1/main.c 

sequence.o: etape1/sequence.c etape1/sequence.h
	$(CC) $(CFLAGS) -c etape1/sequence.c -o etape1/sequence.o

#tab_dynamique
test_tab_dynamique: test_tab_dynamique.c 
	$(CC) $(CFLAGS) test_tab_dynamique.o tab_dynamique.o -o test_tab_dynamique

tab_dynamique.o: etape2/tab_dynamique.c etape2/tab_dynamique.h
	$(CC) $(CFLAGS) -c etape2/tab_dynamique.c
#
clean:
	rm -f *.o test_tab_dynamique
