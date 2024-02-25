#!/bin/bash

# Name: Kaya Unal
# Email address: kayau@csu.fullerton.edu
# Course ID: CPSC131
# OS of the Computer for Development: Linux Ubuntu 20.04.6 LTS Visual Studio Code 
# OS of the Computer for Testing: Linux Ubuntu 20.04.6 LTS

g++ -o music_player music_player.cpp

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running music player..."
    # Run the compiled program
    ./music_player
    # Remove the compiled executable after running
    rm music_player
else
    echo "Compilation failed. Exiting."
fi
