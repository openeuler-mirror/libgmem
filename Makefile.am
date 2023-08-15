# Copyright (c) 2023 yangyanchao6@huawei.com 
# libgmem is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
# See the Mulan PSL v2 for more details.

CLEANFILES = $(BUILE_FILES)
DISTCLEANFILES =
BUILT_FILES =
ACLOCAL_AMFLAGS = ${ACLOCAL_FLGAS}

AM_CFLAGS = \
	-Wall \
	-Werror
AM_LDFLAGS = 

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
