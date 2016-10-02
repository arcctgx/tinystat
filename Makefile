CC = gcc
CCOPTS = -Wall -ansi -pedantic

all: ts-sum ts-avg ts-sdev ts-sigclip ts-hist

ts-sum: ts-sum.c
	$(CC) $(CCOPTS) ts-sum.c -o ts-sum

ts-avg: ts-avg.c
	$(CC) $(CCOPTS) ts-avg.c -o ts-avg

tinystat.o: tinystat.h tinystat.c
	$(CC) $(CCOPTS) -c tinystat.c

ts-sdev: ts-sdev.c tinystat.o
	$(CC) $(CCOPTS) tinystat.o ts-sdev.c -lm -o ts-sdev

ts-sigclip: ts-sigclip.c tinystat.o
	$(CC) $(CCOPTS) tinystat.o ts-sigclip.c -lm -o ts-sigclip

ts-hist: ts-hist.c tinystat.o
	$(CC) $(CCOPTS) tinystat.o ts-hist.c -lm -o ts-hist

clean:
	rm -rf *.o ts-sum ts-avg ts-sdev ts-sigclip ts-hist
