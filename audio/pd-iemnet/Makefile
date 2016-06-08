# $FreeBSD$

PORTNAME=		iemnet
PORTVERSION=		0.2.1
CATEGORIES=		audio
MASTER_SITES=		DEBIAN
MASTER_SITE_SUBDIR=	pool/main/p/pd-${PORTNAME}
PKGNAMEPREFIX=		pd-
DISTNAME=		${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.orig.tar.gz

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Pd library for low-level networking

LICENSE=	GPLv2

BUILD_DEPENDS=	pd:audio/pd
RUN_DEPENDS=	pd:audio/pd

WRKSRC=	${WRKDIR}/${PKGNAME}

USES=	gmake
USE_LDCONFIG=	${PREFIX}/pd-externals/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pd-externals/${PORTNAME}
	${FIND} ${WRKSRC} -name "*.pd" -exec ${INSTALL_DATA} {} \
		${STAGEDIR}${PREFIX}/lib/pd-externals/${PORTNAME} \;
	${FIND} ${WRKSRC} -name "*.pd_linux" -exec ${INSTALL_PROGRAM} {} \
		${STAGEDIR}${PREFIX}/lib/pd-externals/${PORTNAME} \;
	${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/pd-externals/${PORTNAME}
.include <bsd.port.mk>
