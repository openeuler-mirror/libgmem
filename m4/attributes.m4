dnl Check if FLAG in ENV-VAR is supported by compiler and append it
dnl to WHERE-TO-APPEND variable. Note that we invert -Wno-* checks to
dnl -W* as gcc cannot test for negated warnings.
dnl CC_CHECK_FLAG_APPEND([WHERE-TO-APPEND], [ENV-VAR], [FLAG])

AC_DEFUN([CC_CHECK_FLAG_APPEND], [
  AC_CACHE_CHECK([if $CC supports flag $3 in envvar $2],
                 AS_TR_SH([cc_cv_$2_$3]),
                 [eval "AS_TR_SH([cc_save_$2])='${$2}'"
                  eval "AS_TR_SH([$2])='-Werror `echo "$3" | sed 's/^-Wno-/-W/'`'"
                  AC_LINK_IFELSE([AC_LANG_SOURCE([int main(void) { return 0; } ])],
                          [eval "AS_TR_SH([cc_cv_$2_$3])='yes'"],
                          [eval "AS_TR_SH([cc_cv_$2_$3])='no'"])
                  eval "AS_TR_SH([$2])='$cc_save_$2'"])

  AS_IF([eval test x$]AS_TR_SH([cc_cv_$2_$3])[ = xyes],
        [eval "$1='${$1} $3'"])
])

dnl CC_CHECK_FLAGS_APPEND([WHERE-TO-APPEND], [ENV-VAR], [FLAG1 FLAG2])
AC_DEFUN([CC_CHECK_FLAGS_APPEND], [
  for flag in $3; do
    CC_CHECK_FLAG_APPEND($1, $2, $flag)
  done
])
