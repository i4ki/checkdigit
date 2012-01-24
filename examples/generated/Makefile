CC=gcc
CFLAGS=-Wall -O3

SOURCES=generate_precatorios_sc.c
TARGET=generate_precatorios_sc

DVSOURCES=dv.c
DVTARGET=libdv.so.1.0.1

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

dv:
	$(CC) -fPIC $(CFLAGS) $(DVSOURCES) -o $(DVTARGET) -shared -Wl,-soname,libdv.so.1.0.1


