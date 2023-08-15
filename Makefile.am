CLEANFILES = $(BUILE_FILES)
DISTCLEANFILES =
BUILT_FILES =
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLGAS}

AM_CFLAGS = $(OUT_CFLAGS)
AM_LDFLAGS = $(OUT_LDFLAGS)

include_HEADERS = include/libgmem.h
lib_LTLIBRARIES = libgmem.la

libgmem_la_SOURCES = \
	src/libgmem.c

libgmem_la_CFLAGS = $(AM_CFLAGS) \
		    -I$(top_srcdir)/include

libgmem_la_LDFLAGS = $(AM_LDFLAGS)
