# $FreeBSD$

PORTNAME=		libdir
PORTVERSION=		1.9
CATEGORIES=		audio
MASTER_SITES=		DEBIAN
MASTER_SITE_SUBDIR=	pool/main/p/pd-${PORTNAME}
PKGNAMEPREFIX=		pd-
DISTNAME=		${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.orig.tar.gz

MAINTAINER=		brittlehaus@gmail.com
COMMENT=		Provides support for the libdir library format for Pd

LICENSE=		BSD3CLAUSE

BUILD_DEPENDS=		pd:${PORTSDIR}/audio/pd
RUN_DEPENDS=		pd:${PORTSDIR}/audio/pd

PLIST_FILES=		lib/pd-externals/libdir/LICENSE.txt \
			lib/pd-externals/libdir/README.txt \
			lib/pd-externals/libdir/libdir-meta.pd \
			lib/pd-externals/libdir/libdir.pd_linux

WRKSRC=			${WRKDIR}/${DISTNAME}

USES=			gmake

.include <bsd.port.mk>
