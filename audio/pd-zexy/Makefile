# $FreeBSD$

PORTNAME=	zexy
PORTVERSION=	2.2.4
CATEGORIES=	audio
MASTER_SITES=	http://puredata.info/downloads/${PORTNAME}/releases/${PORTVERSION}/
PKGNAMEPREFIX=	pd-

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Swiss army knife for Pure Data

LICENSE=	GPLv2

BUILD_DEPENDS=	pd:${PORTSDIR}/audio/pd
RUN_DEPENDS=	pd:${PORTSDIR}/audio/pd

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		gmake
USE_AUTOTOOLS=	aclocal autoconf
CONFIGURE_ARGS=	--with-pd=${LOCALBASE}/include/pd

pre-configure:
	${REINPLACE_CMD} -e 's|Linux|FreeBSD|' ${WRKSRC}/configure.ac
do-configure:
	cd ${WRKSRC}; ./bootstrap.sh && ./configure ${CONFIGURE_ARGS}

.include <bsd.port.mk>
