CC=gcc
CFLAGS=-Wall -O3

VERSION=1.0.1
DVSOURCES=src/checkdigit.c
DVHEADERS=src/checkdigit.h
DVLIBNAME=libcheckdigit.so
DVTARGET=$(DVLIBNAME).1.0.1

INSTALL_PREFIX=/usr

all:
	$(CC) -O2 -fPIC $(CFLAGS) $(DVSOURCES) -o $(DVTARGET) -shared -Wl,-soname,$(DVTARGET)

install: all
	cp "$(DVHEADERS)" "$(INSTALL_PREFIX)/include/"
	cp "$(DVTARGET)" "$(INSTALL_PREFIX)/lib"
	ln -sf "$(INSTALL_PREFIX)/lib/$(DVTARGET)" $(INSTALL_PREFIX)/lib/$(DVLIBNAME).1.0
	ln -sf "$(INSTALL_PREFIX)/lib/$(DVTARGET)" $(INSTALL_PREFIX)/lib/$(DVLIBNAME).1
	ln -sf "$(INSTALL_PREFIX)/lib/$(DVTARGET)" $(INSTALL_PREFIX)/lib/$(DVLIBNAME)

clean:
	rm -f "$(DVTARGET)"
