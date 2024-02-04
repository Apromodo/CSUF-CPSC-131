#!/bin/bash

g++ -c main.cpp -o main.o
g++ -c Vehicle.cpp -o Vehicle.o
g++ -c Owner.cpp -o Owner.o

g++ main.o Vehicle.o Owner.o -o main_program

./main_program
