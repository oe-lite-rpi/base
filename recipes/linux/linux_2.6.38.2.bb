DESCRIPTION = "Linux Kernel"
HOMEPAGE = "http://www.kernel.org"
LICENSE = "GPLv2"

inherit kernel

require conf/fetch/kernelorg.conf
SRC_URI = "${KERNELORG_MIRROR}/pub/linux/kernel/v2.6/linux-${PV}.tar.bz2"
S = "${SRCDIR}/linux-${PV}"