# $FreeBSD$

PORTNAME=	zexy
PORTVERSION=	2.2.6
CATEGORIES=	audio
MASTER_SITES=	DEBIAN/pool/main/p/pd-${PORTNAME}
PKGNAMEPREFIX=	pd-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Swiss army knife for Pure Data

LICENSE=	GPLv2

BUILD_DEPENDS=	pd:audio/pd
RUN_DEPENDS=	pd:audio/pd

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}-fcb634fdede2b6c71b7c5ee2cea43f05622c126b

USES=		autoreconf gmake libtool
USE_AUTOTOOLS=	aclocal autoconf
CONFIGURE_ARGS=	--with-pd=${LOCALBASE}/include

pre-configure:
	cd ${WRKSRC} && ./autogen.sh
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pd-externals/${PORTNAME}/${PORTNAME}.pd_linux

.include <bsd.port.mk>
