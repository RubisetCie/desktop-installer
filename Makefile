# Compilers
CC = gcc

# Compiler flags
override CFLAGS += -ansi

# Linker flags
override LDFLAGS +=

# Source files
SRC_FILES = \
	main.c

# Installation prefix
PREFIX = /usr/local

TARGET = deskutils

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

install:
	mkdir -p $(PREFIX)
	cp $(TARGET) $(PREFIX)/bin

uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)
