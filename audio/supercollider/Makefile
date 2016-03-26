# $FreeBSD$

PORTNAME=	supercollider
PORTVERSION=	3.7.0
CATEGORIES=	audio
MASTER_SITES=	http://pub.tbrodel.me/FreeBSD/ports/distfiles/

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Programming language for real time audio synthesis

LICENSE=	GPLv2+

CFLAGS+=	"-I${LOCALBASE}/include"
CXXFLAGS+=	"-I${LOCALBASE}/include"

BUILD_DEPENDS=	libXt>0:${PORTSDIR}/x11-toolkits/libXt

WRKSRC=		${WRKDIR}/SuperCollider

LIBDEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		libsndfile.so:${PORTSDIR}/audio/libsndfile

USES=		cmake:outsource shared-mime-info
USE_QT5=	buildtools_build gui linguisttools qmake_build webkit sql

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib/qt5 \
		-DLIBUSB_1_INCLUDE_DIR=/usr/include \
		-DLIBUSB_1_LIBRARY=/usr/lib/libusb.so \
		-DSNDFILE_INCLUDE_DIR=${LOCALBASE}/include/ \
		-DJACK_INCLUDE_DIRS=${LOCALBASE}/include/jack 
		#-DSNDFILE_LIBRARY=${LOCALBASE}/lib/libsndfile.so \
		-DJACK_LIBRARIES=${LOCALBASE}/lib/libjack.so 

.include <bsd.port.mk>
