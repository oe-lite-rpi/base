DESCRIPTION = "library to provide userspace access to USB devices"
HOMEPAGE = "http://libusb.sf.net"
SECTION = "libs"
LICENSE = "LGPLv2.1"

PR = "r0"

SRC_URI = "${SOURCEFORGE_MIRROR}/libusb/libusb-${PV}.tar.bz2;name=tar"
S = "${WORKDIR}/libusb-${PV}"

DEPENDS = "${TARGET_ARCH}/sysroot-libpthread"

inherit autotools

EXTRA_OECONF = "--disable-build-docs"