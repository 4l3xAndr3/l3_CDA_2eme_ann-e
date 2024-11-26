CC = gcc
CFLAGS = -Wall -Wextra -g

all: test_tab_dynamique

test_tab_dynamique: test_tab_dynamique.o tab_dynamique.o
	$(CC) $(CFLAGS) -o test_tab_dynamique test_tab_dynamique.o tab_dynamique.o

test_tab_dynamique.o: test_tab_dynamique.c tab_dynamique.h
	$(CC) $(CFLAGS) -c test_tab_dynamique.c

tab_dynamique.o: tab_dynamique.c tab_dynamique.h
	$(CC) $(CFLAGS) -c tab_dynamique.c

clean:
	rm -f *.o test_tab_dynamique
