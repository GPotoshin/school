.PHONY: clear all


printState.o: func/printState.c func/printState.h
	cc -Wall -c -o bin/printState.o func/printState.c

genDate.o: func/genDate.c func/genDate.h
	cc -Wall -c -o bin/genDate.o func/genDate.c

main.o: main.c myls.h
	cc -Wall -c -o bin/main.o main.c

myls: bin/main.o bin/genDate.o bin/printState.o
	cc -o myls bin/*.o

all:
	make printState.o genDate.o main.o myls

clear:
	rm bin/main.o bin/genDate.o bin/printState.o
