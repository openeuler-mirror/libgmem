# Copyright (c) 2023 yangyanchao6@huawei.com 
# libgmem is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
# See the Mulan PSL v2 for more details.

AC_PREREQ([2.65])
AC_INIT([libgmem],
        [1],
        [https://gitee.com/src-openeuler/libgmem],
        [libgmem],
        [http://gitee.com/openeuler/libgmem.git])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])
AC_SUBST([libdir], ['${prefix}/lib64'])

AC_USE_SYSTEM_EXTENSIONS
AC_PREFIX_DEFAULT([/usr])
AM_MAINTAINER_MODE([enable])
AM_INIT_AUTOMAKE([foreign silent-rules subdir-objects])
AM_SILENT_RULES([yes])
LT_INIT([disable-static pic-only])

#####################################################################
# Program checks and configurations
#####################################################################
AC_PROG_CC
AC_PROG_INSTALL
PKG_PROG_PKG_CONFIG

#####################################################################
# Function and structure checks
#####################################################################
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h unistd.h linux/mman.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS_ONCE(syscall)

AC_MSG_CHECKING([whether _Noreturn is supported])
AC_COMPILE_IFELSE(
        [AC_LANG_SOURCE([[_Noreturn int foo(void) { exit(0); }]])],
        [AC_DEFINE([HAVE_NORETURN], [1], [Define if _Noreturn is available])
         AC_MSG_RESULT([yes])],
        [AC_MSG_RESULT([no])])

#####################################################################
# --with-
#####################################################################
AC_ARG_WITH([device],
            AS_HELP_STRING([--with-device=DEVICE_TYPE],
                           [the DEVICE_TYPE for used, such as Ascend]),
            [device_type=$withval])

AM_CONDITIONAL([BUILD_FOR_ASCEND], [test "x$with_device" = "xAscend"])
case "$with_device" in
  Ascend)
    AC_DEFINE(DEVICE_TYPE, [1], [USE ASCEND]);;
  '')
     AC_MSG_ERROR([MUST SPECIFIES DEVICE TYPE, USE --with-device]);;
  *)
    AC_MSG_ERROR([unknow device type, please use Ascend]);;
esac

#####################################################################
# Default CFLAGS and LDFLAGS
#####################################################################
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
AC_MSG_RESULT([
	$PACKAGE $VERSION
	=======

	prefix:			${prefix}
	sysconfdir:		${sysconfdir}
	libdir:			${libdir}
	rootlibdir:		${rootlibdir}
	includedir:		${includedir}
	bindir:			${bindir}

	compiler:		${CC}
	cflags:			${CFLAGS}
	ldflags:		${LDFLAGS}
])
