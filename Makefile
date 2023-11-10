CC = gcc
CFLAGS = -Wall -std=c11
LIBS = -lmicrohttpd

TARGET = server

all: $(TARGET)

$(TARGET): server.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean

clean:
	rm -f $(TARGET)
