.PHONY: bin clean all include

CCFLAGS += -pipe -O2 -g -fPIC
LDFLAGS += -lm -lpng

BOLD ?= `[ -z $${TERM} ] && echo "" || tput bold`
UNDERLINE ?= `[ -z $${TERM} ] && echo "" || tput smul`
ANSI_RESET ?= `[ -z $${TERM} ] && echo "" || tput sgr0`
CARGO_COLOR ?= `[ -z $${NO_COLOR+x} ] && echo "" || echo "--color=never "`
RED ?= `[ -z $${NO_COLOR+x} ] && ([ -z $${TERM} ] && echo "" || tput setaf 1) || echo ""`

OBJECTF := bin/grooph_essence.o bin/grooph_draw.o bin/grizmos.o

ifeq ($(test -d bin && echo 1 || echo 0), 1)
	ALL := bin/grooph.so
else
	ALL := bin bin/grooph.so
endif

all: $(ALL)

help:
	@echo "NO help, do on your own"

bin:
	mkdir -p bin

bin/grizmos.o: src/tools/grizmos.c src/tools/grizmos.h
	cc $(CCFLAGS) -c -o $@ src/tools/grizmos.c

bin/grooph_essence.o: src/grooph_essence.c src/grooph_essence.h src/grooph_core.h src/grooph_defs.h
	cc $(CCFLAGS) -c -o $@ src/grooph_essence.c

bin/grooph_draw.o: src/grooph_draw.c src/grooph_draw.h src/grooph_core.h src/grooph_defs.h
	cc $(CCFLAGS) -c -o $@ src/grooph_draw.c

bin/grooph.so: $(OBJECTF)
	cc $(LDFLAGS) -shared -o $@ $(OBJECTF)

include:
	cp src/grooph.h include
	cp src/grooph_draw.h include
	cp src/grooph_core.h include
	cp src/grooph_essence.h include

clean:
	rm -f $(OBJECTF) bin/grooph.so
