#!/bin/bash

# Ensure that at least one argument is provided to the script
if [ $# -eq 0 ]; then
    exit 1
fi

# Compile the C program
gcc project1.c

# Check if compilation was successful
if [ $? -ne 0 ]; then
    exit 1
fi

# Run the program with provided arguments
./a.out "$@"
