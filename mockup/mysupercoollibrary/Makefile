all: libsuper.so


CFLAGS=-fPIC
LD=gcc
LDFLAGS=-O3

super.o: super.h super.c
	$(CC) $(CFLAGS) super.c -c -o super.o

libsuper.so: super.o
	$(LD) $(LDFLAGS) -fPIC -shared -o libsuper.so super.o
