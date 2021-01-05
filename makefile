CC=gcc
AR=ar

FLAGS= -Wall -g

all: isort txtfind 

isort: main1.o isort.o
	$(CC) $(FLAGS) -o isort main1.o isort.o

isort.o: isort.c isort.h  
	$(CC) $(FLAGS) -c isort.c 
	
main1.o: main1.c isort.h 
	$(CC) $(FLAGS) -c main1.c
	
txtfind: main2.o txtfind.o
	$(CC) $(FLAGS) -o txtfind main2.o txtfind.o
	 
txtfind.o: txtfind.c txtfind.h  
	$(CC) $(FLAGS) -c txtfind.c 
	
main2.o: main2.c txtfind.h 
	$(CC) $(FLAGS) -c main2.c




.PHONY: clean all

clean:
	rm -f *.o *.a *.so .out isort txtfind
