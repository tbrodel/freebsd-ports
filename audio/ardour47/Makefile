# $FreeBSD$

PORTNAME=	ardour
PORTVERSION=	4.7
CATEGORIES=	audio
MASTER_SITES=	https://github.com/Ardour/ardour/archive/ \
		http://pub.tbrodel.me/FreeBSD/ports/distfiles/
DISTFILES=	${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-revision.cc
EXTRACT_ONLY=	${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Free and open source digital audio workstation

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		lv2>0:${PORTSDIR}/audio/lv2
LIB_DEPENDS=	libboost_atomic.so:${PORTSDIR}/devel/boost-libs \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libcurl.so:${PORTSDIR}/ftp/curl \
		liblo.so:${PORTSDIR}/audio/liblo \
		libtag.so:${PORTSDIR}/audio/taglib \
		libvamp-sdk.so:${PORTSDIR}/audio/vamp-plugin-sdk \
		librubberband.so:${PORTSDIR}/audio/rubberband \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libaubio.so:${PORTSDIR}/audio/aubio \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf

USES=		gettext pkgconfig waf
USE_GNOME=	glib20 glibmm gtk20 gtkmm24
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--with-backends=jack --boost-include=${LOCALBASE}/include \
		--freebie --freedesktop --no-lv2 --no-nls

post-extract:
	${CP} ${DISTDIR}/${PORTNAME}-revision.cc \
		${WRKSRC}/libs/${PORTNAME}/revision.cc
	${REINPLACE_CMD} -e 's|REVISION|${PORTVERSION}|' \
		${WRKSRC}/libs/${PORTNAME}/revision.cc
	#${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/waf
	#${FIND} ${WRKSRC} -name "wscript" -exec ${REINPLACE_CMD} -e \
		's|/usr/bin/env python|${PYTHON_CMD}|' {} \;
do-configure:
	cd ${WRKSRC} && ./waf configure ${CONFIGURE_ARGS}
#do-install:
#	cd ${WRKSRC} && ./waf install --destdir=${STAGEDIR}
post-install:
.for f in sanityCheck ${PORTNAME}-vst-scanner \
${PORTNAME}-exec-wrapper h${PORTNAME}-${PORTVERSION}.0 \
${PORTNAME}-${PORTVERSION}.0
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/${PORTNAME}4/${f}
.endfor
	${FIND} ${STAGEDIR}${LOCALBASE}/lib/${PORTNAME}4/ -name "*.so*" \
		-exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
