# gcc - compiler
CC=gcc
#compiler flags
CFLAGS=-o NSHOOT.exe -lgdi32 -lws2_32
#main file
MAIN=main

default: build

build: .o
	$(CC) $(MAIN).o $(CFLAGS)

linux: .o
	$(CC) $(MAIN).o -lm

clean: clean.o
	del NSHOOT.exe

cleanix.o: 
	rm *.o

clean.o:
	del *.o

.o:
	$(CC) $(MAIN).c -c
