# Makefile for matrix multiplication program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source files
SRC = main.c matrix_multiplication.c

# Header files
HDR = matrix_multiplication.h

# Target executable
TARGET = matMultp

# Build target
$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean target
clean:
	rm -f $(TARGET)
