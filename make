CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm

# Object files
OBJS = main.o sequence.o
STATIC_OBJS = hash_x86_64.o list_x86_64.o

# Output binary
TARGET = program

all: $(TARGET)

# Link all objects to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(STATIC_OBJS) $(LDFLAGS)

# Compile C files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Deep clean removes everything, including hash_x86_64.o and list_x86_64.o
deep_clean: clean
	rm -f $(STATIC_OBJS)

.PHONY: all clean deep_clean
