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

if BUILD_FOR_ASCEND
ASCEND_PATH=/usr/local/Ascend/ascend-toolkit/latest/aarch64-linux

libgmem_la_SOURCES += \
	src/ascend/gmem_ascend.c

AM_CFLAGS += \
	-I$(top_srcdir)/src/ascend \
	-I$(ASCEND_PATH)/include

AM_LDFLAGS += \
	-lascendcl \
	-L$(ASCEND_PATH)/lib64/
endif
