DESCRIPTION = "Update daemon watching a dir for firmware updates"
LICENSE = "GPLv2"

RECIPE_FLAGS = "\
	dupdate_backend \
	dupdate_imagemode \
	dupdate_sysvinit_start \
	dupdate_sysvinit_stop \
"

DEFAULT_USE_dupdate_backend = "mtd"
DEFAULT_USE_dupdate_imagemode = "dual"

inherit sysvinit
DEFAULT_USE_dupdate_sysvinit_start = "60"
RDEPENDS_${PN}:>USE_sysvinit += "util/start-stop-daemon"

SRC_URI = "git://oe-lite.org/dupdate.git;protocol=git;${SRC_REV}"
S = "${SRCDIR}/dupdate"

inherit autotools

EXTRA_OECONF += "--with-backend=${USE_dupdate_backend}"
EXTRA_OECONF += "--with-imagemode=${USE_dupdate_imagemode}"

INSTALL_SYSVINIT_POSTFUNC = ""
INSTALL_SYSVINIT_POSTFUNC:USE_sysvinit = "do_install_sysvinit_dupdate"
do_install[postfuncs] =+ "${INSTALL_SYSVINIT_POSTFUNC}"
do_install_sysvinit_dupdate () {
    sysvinit_install_script ${S}/src/dupdate.sh dupdate
}

inherit splashutils-progress
RECIPE_FLAGS += "dupdate_splashutils_progress dupdate_splashutils_msg"
SPLASHUTILS_INITSCRIPTS = ""
SPLASHUTILS_INITSCRIPTS:USE_sysvinit = "dupdate"
DEFAULT_USE_dupdate_splashutils_msg = "\"Starting Dupdate Daemon\""
