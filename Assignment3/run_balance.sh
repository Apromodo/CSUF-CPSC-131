#!/bin/bash

CXX=g++
SOURCE="balance.cpp"
OUTPUT="balance"
CXXFLAGS="-std=c++17 -Wall -Wextra"

# Command to compile the C++ source code
$CXX $CXXFLAGS -o $OUTPUT $SOURCE

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    echo "This program is maintained by Kaya Unal"
    ./$OUTPUT
    rm $OUTPUT
else
    echo "Compilation failed."
fi
