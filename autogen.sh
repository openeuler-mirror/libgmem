#!/bin/sh

cd `dirname "$0"`

ACLOCAL=${ACLOCAL:-aclocal}
AUTOCONF=${AUTOCONF:-autoconf}
AUTOHEADER=${AUTOHEADER:-autoheader}
AUTOMAKE=${AUTOMAKE:-automake}
LIBTOOLIZE=${LIBTOOLIZE:-libtoolize}

set -ex
"$LIBTOOLIZE" --copy
"$ACLOCAL" -I m4
"$AUTOCONF"
"$AUTOHEADER"
"$AUTOMAKE" --add-missing --copy
