###############################################################################
#
#Makefile for 'pcrd'
#
###############################################################################

CC=gcc
CFLAGS=

all: linux

help:
	@echo "Target(s): linux debug_linux clean"

linux: pcrd.c pcrd.h
	$(CC) $(CFLAGS) -o pcrd pcrd.c

debug_linux:    pcrd.c pcrd.h
	$(CC) $(CFLAGS) -ggdb -o pcrd pcrd.c

clean:
	rm -f pcrd
