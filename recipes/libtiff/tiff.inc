DESCRIPTION = "This software provides support for the Tag Image File Format (TIFF)"
LICENSE = "BSD-2-Clause*"
HOMEPAGE = "http://www.remotesensing.org/libtiff/"

SRC_URI = "ftp://ftp.remotesensing.org/pub/libtiff/tiff-${PV}.tar.gz"

inherit autotools c++

OECONF_ARCHTUPLE = "ax_cv_check_gl_libgl=no"

PACKAGES =+ "${PN}-staticdev ${PN}-utils ${PN}-utils-dbg"
FILES_${PN} += "${libdir}/libtiffxx.so.*"
FILES_${PN}-dev += "${libdir}/libtiffxx.so ${libdir}/libtiffxx.la"
FILES_${PN}-staticdev = "${libdir}/libtiffxx.a"
FILES_${PN}-dbg += "${libdir}/.debug/libtiffxx.so*"
FILES_${PN}-utils = "${bindir}/*"
FILES_${PN}-utils-dbg += "${bindir}/.debug/"
