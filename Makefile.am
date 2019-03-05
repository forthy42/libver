# Automake file for libver dummy library

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4
AM_CPPFLAGS = $(EXAMPLE_CFLAGS)

lib_LTLIBRARIES = libver10.la libver11.la libver20.la libver23.la
libver10_la_SOURCES = libver-1.0.c
libver11_la_SOURCES = libver-1.1.c
libver20_la_SOURCES = libver-2.0.c
libver23_la_SOURCES = libver-2.3.c

distclean-local: clean-am distclean-compile distclean-hdr distclean-libtool distclean-tags

install-exec-hook:
	-/sbin/ldconfig $(libdir)

tests: testver testver1 testver10 testver11 testver2 testver20 testver23

testver:	libver10.la libver11.la libver20.la libver23.la
	gcc -lver -L. test.c -Xlinker -rpath $$PWD/.libs -o testver
testver1:	libver10.la libver11.la
	gcc -lver1 -DVER_MAJ=1 -L. test.c -Xlinker -rpath $$PWD/.libs -o testver1
testver10:	libver10.la
	gcc -lver10 -DVER_MAJ=1 -DVER_MIN=0 -L. test.c -Xlinker -rpath $$PWD/.libs -o testver10
testver11:	libver10.la libver11.la
	gcc -lver11 -DVER_MAJ=1 -DVER_MIN=1 -L. test.c -Xlinker -rpath $$PWD/.libs -o testver11
testver2:	libver10.la libver11.la libver20.la
	gcc -lver2 -DVER_MAJ=2 -L. test.c -Xlinker -rpath $$PWD/.libs -o testver2
testver20:	libver10.la libver11.la libver20.la
	gcc -lver20 -DVER_MAJ=2 -DVER_MIN=0 -L. test.c -Xlinker -rpath $$PWD/.libs -o testver20
testver23:	libver10.la libver11.la libver20.la libver23.la
	gcc -lver23 -DVER_MAJ=2 -DVER_MIN=3 -L. test.c -Xlinker -rpath $$PWD/.libs -o testver23
