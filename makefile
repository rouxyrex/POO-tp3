SHELL=/bin/bash

CC=g++
LD=g++

CFLAGS=-Wall -g -O0 -ansi -pedantic -std=c++11 -fPIC
LDFLAGS=-lm

EXEC=main
SRC=$(wildcard *.cpp)
OBJECTS=$(SRC:.cpp=.o)

PHONY: target clean

target:$(EXEC)

%.o: %.cpp %.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)
	
clean:
	rm -f *.o core

