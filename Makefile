# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Source and object files
SRCS = $(SRC_DIR)/dynamicArray.c main.c
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create the binary
$(TARGET): ${OBJS}
		$(CC) $(CFLAGS) -o $@ $^
	
# Compile source files int object files
%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build files
clean:
		rm -f $(OBJS) $(TARGET)
