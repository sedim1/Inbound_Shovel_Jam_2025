#!/bin/bash

# Compile the program
gcc -o Shovel_Jam src/*.c -Iinclude -lraylib -lm

# Check if the compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. Running the program..."
  ./Shovel_Jam
else
  echo "Compilation failed. Program not executed."
fi
