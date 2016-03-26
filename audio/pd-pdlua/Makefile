# $FreeBSD$

PORTNAME=		pdlua
PORTVERSION=		0.7.3
CATEGORIES=		audio
MASTER_SITES=		DEBIAN
MASTER_SITE_SUBDIR=	pool/main/p/pd-lua
PKGNAMEPREFIX=		pd-
DISTNAME=		${PKGNAMEPREFIX}lua_${PORTVERSION}
EXTRACT_SUFX=		.orig.tar.gz

MAINTAINER=		brittlehaus@gmail.com
COMMENT=		Lua bindings for Pure Data

LICENSE=		GPLv2

BUILD_DEPENDS=	pd:${PORTSDIR}/audio/pd
RUN_DEPENDS=	pd:${PORTSDIR}/audio/pd

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/

USES=			gmake lua:build,run

pre-patch:
	${REINPLACE_CMD} -e \
		's|/usr/include/lua|${LOCALBASE}/include/lua${LUA_VER_STR}|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-llua|-llua-${LUA_VER}|' ${WRKSRC}/Makefile
.include <bsd.port.mk>
