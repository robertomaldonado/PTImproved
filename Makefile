# File:   Makefile
# Author: robertomaldonado
# Created on November 30, 2017

# Declare CC
CC=g++ -std=c++11 
CFLAGS = -O2#-Wall
#Declare processes
all: generateFiles compile
#Create .o files
generateFiles: 
	$(CC) $(CFLAGS) -c main.cpp TextParser.cpp Analyzer.cpp FileHandler.cpp
#Link to executable
compile: main.o TextParser.o Analyzer.o FileHandler.o
	$(CC) $(CFLAGS) main.o TextParser.o Analyzer.o FileHandler.o -o executable
#Clean directoty
clean:
	rm *.o executable