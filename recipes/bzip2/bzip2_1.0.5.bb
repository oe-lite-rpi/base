DESCRIPTION = "Very high-quality data compression program"
SECTION = "console/utils"

LICENSE = "bzip2"
FILESPATHPKG =. "bzip2-${PV}:"
SRC_URI = "http://www.bzip.org/${PV}/bzip2-${PV}.tar.gz \
	   file://bzip2-1.0.5-autoconfiscated.patch;patch=1"

inherit autotools pkgconfig

do_configure_prepend () {
	if test -f LICENSE ; then sh ./autogen.sh ; fi
}

BBCLASSEXTEND = "native"
