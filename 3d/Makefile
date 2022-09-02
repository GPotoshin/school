CC_FLAGS+=-O2

ifeq ($(test -d bin && echo 1 || echo 0), 1)
	ALL := bin/3d
else
	ALL := bin bin/3d
endif

all: $(ALL)

bin:
	mkdir -p bin

bin/3d: src/main.c bin/grooph.so
	$(CC) $(CC_FLAGS) -o $@ src/main.c bin/grooph.so