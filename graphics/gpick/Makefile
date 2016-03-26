# $FreeBSD$

PORTNAME=	gpick
PORTVERSION=	0.2.5
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/thezbyg/${PORTNAME}/archive/ \
		http://pub.tbrodel.me/FreeBSD/ports/distfiles/

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Advanced color picker written in C++ using GTK+ toolkit

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_atomic.so:${PORTSDIR}/devel/boost-libs \
		libexpat.so:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lexpat

USES=		desktop-file-utils gettext lua:build,run pkgconfig scons
USE_GNOME=	gtk20
GTK2_VERSION=	2.24.29

post-patch:
	${REINPLACE_CMD} -e 's|lua5.2|lua-${LUA_VER}|' ${WRKSRC}/SConscript
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/source/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/share/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/share/applications && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DESKTOPDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/share/doc/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.include <bsd.port.mk>
