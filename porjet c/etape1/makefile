# Nom du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g

# Fichiers sources et objets
SRCS = main.c sequence.c
OBJS = main.o sequence.o
PRECOMPILED_OBJS = hash_x86_64.o list_x86_64.o

# Nom de l'exécutable
TARGET = program

# Règle par défaut
all: $(TARGET)

# Construction de l'exécutable
$(TARGET): $(OBJS) $(PRECOMPILED_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm -Wl,--image-base=0x140000000

# Compilation des fichiers sources en fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)
