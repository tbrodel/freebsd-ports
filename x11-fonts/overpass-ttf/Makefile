# $FreeBSD$

PORTNAME=	overpass
PORTVERSION=	2.1
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Open source font family sponsored by Red Hat

LICENSE=	OFL11 LGPL21
LICENSE_COMB=	multi
LICENSE_NAME=	SIL Open Font License version 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell

USE_GITHUB=	yes
GH_ACCOUNT=	RedHatBrand
GH_PROJECT=	${PORTNAME}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/fonts/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/Desktop\ Fonts/*.ttf \
		${STAGEDIR}${LOCALBASE}/share/fonts/${PORTNAME}

.include <bsd.port.mk>
