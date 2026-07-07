CC = gcc
CFLAGS = -I include -Wall
SRCS = src/main.c src/file_io.c src/expense_ops.c
TARGET = expense_tracker

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)