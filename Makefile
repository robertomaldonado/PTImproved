# File:   Makefile
# Author: robertomaldonado
# Created on November 30, 2017

# Declare CC
CC=g++ -std=c++11 
CFLAGS = -Wall
#Declare processes
all: generateFiles compile
#Create .o files
generateFiles: 
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -c TextParser.cpp -o TextParser.o
	$(CC) $(CFLAGS) -c Analyzer.cpp -o Analyzer.o
	$(CC) $(CFLAGS) -c FileHandler.cpp -o FileHandler.o
#Link to executable
compile: main.o TextParser.o Analyzer.o FileHandler.o
	$(CC)  main.o TextParser.o Analyzer.o FileHandler.o -o executable
#Clean directoty
clean:
	rm *.o executable
clean_files:
	rm files/default_?.txtplot_averages.txt
	rm files/default_?.txtplot_greeting.txt
	rm files/default_?.txtplot_mayus.txt
	rm files/default_?.txtplot_minus.txt
	rm files/default_?.txtplot_numbers.txt
	rm files/default_?.txtplot_tildes.txt
	rm files/default_?.txtplot_totales.txt
	rm files/default_?.txtplot.txt
	


