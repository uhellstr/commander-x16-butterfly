ALL_C = $(wildcard *.c) $(wildcard *.h)

all: $(ALL_C)
	cl65 -Oi -t cx16 -o BUTTERFLY.PRG -l butterfly.list butterfly.c

clean:
	rm -f *.PRG *.list *.o
