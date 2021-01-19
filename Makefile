CC=gcc 
AR=ar
FLAGS= -Wall -g 


all: frequency

frequency: main.o treeFunctions.o treeFunctions.h
	$(CC) $(Flags) -o frequency main.o treeFunctions.o

main.o: main.c treeFunctions.h
	$(CC) $(FLAGS) -c main.c

treeFunctions.o: treeFunctions.c treeFunctions.h
	$(CC) $(FLAGS) -c treeFunctions.c 



.PHONY: clean all 

clean: 
	rm -f *.o frequency

