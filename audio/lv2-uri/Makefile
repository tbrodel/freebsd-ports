# $FreeBSD$

PORTNAME=	uri
PORTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/ns/ext/${PORTNAME}-map/ \
		http://lv2plug.in/ns/ext/${PORTNAME}d/
PKGNAMEPREFIX=	lv2-
DISTFILES=	${PORTNAME}d.h \
		${PORTNAME}-map.h
EXTRACT_ONLY=

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Lv2 feature for mapping URIs to integers

NO_BUILD= 	YES

PLIST_FILES=	include/lv2/lv2plug.in/ns/ext/${PORTNAME}d/${PORTNAME}d.h \
		include/lv2/lv2plug.in/ns/ext/${PORTNAME}-map/${PORTNAME}-map.h \

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/include/lv2/lv2plug.in/ns/ext/${PORTNAME}d
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}d.h ${STAGEDIR}${LOCALBASE}/include/lv2/lv2plug.in/ns/ext/${PORTNAME}d/
	${MKDIR} ${STAGEDIR}${LOCALBASE}/include/lv2/lv2plug.in/ns/ext/${PORTNAME}-map
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-map.h ${STAGEDIR}${LOCALBASE}/include/lv2/lv2plug.in/ns/ext/${PORTNAME}-map/

.include <bsd.port.mk>
