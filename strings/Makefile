.PHONY: all clear

CFLAGS += -Wall -O2 -pipe

all: inverse sort

inverse: inverse.c
	$(CC) $(CFLAGS) inverse.c -o inverse

sort: sort.c
	$(CC) $(CFLAGS) sort.c -o sort

clear:
	rm -f inverse sort
