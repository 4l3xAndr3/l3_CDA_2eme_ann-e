CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm


OBJS = main.o sequence.o
STATIC_OBJS = hash_x86_64.o list_x86_64.o


TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(STATIC_OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 