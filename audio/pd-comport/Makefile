# $FreeBSD$

PORTNAME=	comport
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://sourceforge.net/projects/pure-data/files/libraries/${PORTNAME}/
PKGNAMEPREFIX=	pd-

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Object for Pd enabling access to serial devices

LICENSE=	LGPL21

BUILD_DEPENDS=	pd:audio/pd
RUN_DEPENDS=	pd:audio/pd

PLIST_FILES=	lib/pd-externals/comport/LICENSE.txt \
		lib/pd-externals/comport/README.txt \
		lib/pd-externals/comport/comport-help.pd \
		lib/pd-externals/comport/comport-meta.pd \
		lib/pd-externals/comport/comport.pd_linux

USES=		gmake
.include <bsd.port.mk>
