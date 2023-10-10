CC = gcc
CFLAGS = -Wall

SRCDIR = ./src
OBJDIR = ./src
BINDIR = .

# List of source files
SRCS = $(wildcard $(SRCDIR)/*.c)
# Generate a list of object files from source files
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
# Name of the final executable
TARGET = $(BINDIR)/my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
