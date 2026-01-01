###############################################################################
#
#Makefile for 'pcrd'
#
###############################################################################

CC=gcc
CFLAGS=

all: linux

help:
	@echo "Target(s): linux freebsd debug_linux debug_freebsd clean"

freebsd: pcrd.c pcrd.h
	$(CC) $(CFLAGS) -o pcrd pcrd.c

debug_freebsd:    pcrd.c pcrd.h
	$(CC) $(CFLAGS) -ggdb -o pcrd pcrd.c

linux: pcrd.c pcrd.h
	$(CC) $(CFLAGS) -DLINUX -o pcrd pcrd.c

debug_linux:    pcrd.c pcrd.h
	$(CC) $(CFLAGS) -DLINUX -ggdb -o pcrd pcrd.c

clean:
	rm -f pcrd
