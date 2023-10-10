# Define the compiler for Mingw
CC = gcc

# Define compilation flags
CFLAGS = -Wall -Werror

# Define source files and object files
SOURCES = boards.c magicBoards.c bitboards.c moves.c chess.c# Add all your source files here
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
