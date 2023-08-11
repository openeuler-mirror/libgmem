AC_PREREQ([2.65])
AC_INIT([libgmem],
        [1],
        [https://gitee.com/src-openeuler/libgmem],
        [libgmem],
        [http://gitee.com/openeuler/libgmem.git])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_MACRO_DIR([m4])
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
                           [the DEVICE_TYPE for used]),
            [device_type=$withval])

case "$with_device" in
  '')
     AC_MSG_ERROR([MUST SPECIFIES DEVICE TYPE, USE --with-device]);;
  *)
    AC_MSG_ERROR([unknow device type]);;
esac

#####################################################################
# Default CFLAGS and LDFLAGS
#####################################################################

CC_CHECK_FLAGS_APPEND(with_cflags, [CFLAGS], [ \
                      -Wall \
		      -Werror])
AC_SUBST([OUT_CFLAGS], "$with_cflags")

CC_CHECK_FLAGS_APPEND(with_ldflags, [LDFLAGS], [\
                      ])
AC_SUBST([OUT_LDFLAGS], "$with_ldflags")

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
	cflags:			${with_cflags} ${CFLAGS}
	ldflags:		${with_ldflags} ${LDFLAGS}
])
