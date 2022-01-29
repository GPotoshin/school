.PHONY: clean

CFLAGS += -O2 -pipe -lpng

queens: queens.c
	cc $(CFLAGS) -o queens queens.c

clean: 
	rm queens img/*.png
