# -*- mode:python; -*-
DESCRIPTION = "Freetype font rendering library"
LICENSE = "freetype GPLv2"

RECIPE_TYPES = "machine native"

inherit library autotools pkgconfig binconfig

DEPENDS = "libz"

require conf/fetch/savannah.conf
SRC_URI = "${SAVANNAH_MIRROR}/freetype/freetype-${PV}.tar.bz2"

SRC_URI += "file://no-hardcode.patch"

do_compile[postfuncs] += "do_compile_apinames"
do_compile_apinames() {
	${BUILD_CC} -o objs/apinames src/tools/apinames.c
}

FILES_${PN} = "${sharedlibdir}/lib*${SOLIBS}"
FILES_${PN}-dev += "${bindir}"
