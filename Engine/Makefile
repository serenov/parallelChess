# Define the compiler for Mingw
CC = gcc

# Define compilation flags
CFLAGS = -Wall -Werror

# Define source files and object files

SRC_DIR = src

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Define the output executable
EXECUTABLE = a.exe

# Default target
all: $(EXECUTABLE)

# Rule to build the executable from object files
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony target for cleaning
.PHONY: clean
