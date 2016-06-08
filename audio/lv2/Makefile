# Created by: Radim Kolar <hsn@sanatana.localdomain>
# $FreeBSD$

PORTNAME=	lv2
PORTVERSION=	1.10.0
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Open standard for audio plugins

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

USES=	tar:bz2 python:build pkgconfig
CONFLICTS_INSTALL=	l2core

USE_GNOME=	gtk20 cairo

do-configure:
		cd ${WRKSRC} && ./waf configure --prefix=${PREFIX} --destdir=${STAGEDIR}

do-build:
		cd ${WRKSRC} && ./waf build

do-install:
		cd ${WRKSRC} && ./waf install --prefix=${PREFIX} --destdir=${STAGEDIR}
		${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* ${STAGEDIR}${PREFIX}/libdata/pkgconfig
		${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig

.include <bsd.port.mk>
