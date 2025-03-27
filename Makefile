# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Directories
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include

# Source and object files
SRCS = $(SRC_DIR)/dynamicArray.c $(TEST_DIR)/testDynamicArray.c $(SRC_DIR)/linkedList.c $(TEST_DIR)/testLinkedList.c $(SRC_DIR)/stack.c $(TEST_DIR)/testStack.c main.c
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
