DESCRIPTION = "802.1q vlan support program"

RECIPE_TYPES = "machine"

inherit c make

SRC_URI = "http://www.candelatech.com/~greear/vlan/vlan.${PV}.tar.gz"
SRC_URI += "file://vlan-up file://vlan-pre-up file://vlan-post-down"

S = "${SRCDIR}/vlan"

do_configure() {
	${MAKE} clean
	rm -f vconfig macvlan_config
}

do_compile() {
	oe_runmake vconfig
}

do_install() {
	install -d "${D}${sbindir}"
	install -m 755 "${S}/vconfig" "${D}${sbindir}/vconfig"
	install -d ${D}${sysconfdir}/network/if-up.d
	install -d ${D}${sysconfdir}/network/if-pre-up.d
	install -d ${D}${sysconfdir}/network/if-post-down.d
	install -m 0755 ${SRCDIR}/vlan-up \
		${D}${sysconfdir}/network/if-up.d/vlan
	install -m 0755 ${SRCDIR}/vlan-pre-up \
		${D}${sysconfdir}/network/if-pre-up.d/vlan
	install -m 0755 ${SRCDIR}/vlan-post-down \
		${D}${sysconfdir}/network/if-post-down.d/vlan
}

PACKAGES =+ "${PN}-ifupdown"
FILES_${PN}-ifupdown = "${sysconfdir}/network"
