.PHONY: clear all

CCFLAGS += -pipe -O2 -g
LDFLAGS += -lm -lpng

all: bin/grooph.so

bin/GRizmos.o: src/GRizmos.c src/GRizmos.h
	cc $(CCFLAGS) -c src/GRizmos.c -o bin/GRizmos.o

bin/GREssence.o: src/GREssence.c src/GREssence.h src/GRTypes.h src/GRDefs.h
	cc $(CCFLAGS) -c src/GREssence.c -o bin/GREssence.o

bin/GRDraw.o: src/GRDraw.c src/GRDraw.h src/GRTypes.h src/GRDefs.h
	cc $(CCFLAGS) -c src/GRDraw.c -o bin/GRDraw.o

bin/grooph.so: bin/GREssence.o bin/GRDraw.o bin/GRizmos.o
	cc $(LDFLAGS) -shared bin/GREssence.o bin/GRDraw.0 bin/GRizmos.o -o bin/grooph.so

clear:
	rm -f bin/GREssence.o bin/GRizomos.o bin/GRDraw.o bin/grooph.so
