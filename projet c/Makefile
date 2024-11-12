test: hash_x86_64.o list_x86_64.o  sequence.o main.o
	gcc -o main -W -Wall hash_x86_64.o list_x86_64.o sequence.o main.o $(shell pkg-config --cflags --libs glib-2.0) -lm

main.o: main.c
	gcc -c -W -Wall main.c

sequence.o: sequence.c
	gcc -c -W -Wall sequence.c