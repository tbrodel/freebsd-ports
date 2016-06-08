# $FreeBSD$

PORTNAME=	numix
PORTVERSION=	20160401
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	-icons

MAINTAINER=	brittlehaus@gmail.com
COMMENT=	Icon theme from the Numix project

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_TUPLE=	${PORTNAME}project:${PORTNAME}-icon-theme:85e58a2:DEFAULT \
		${PORTNAME}project:${PORTNAME}-icon-theme-circle:56e0ffc:apps

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/Numix
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/Numix-Light
	(cd ${WRKSRC}/Numix && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LOCALBASE}/share/icons/Numix)
	(cd ${WRKSRC}/Numix-Light && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LOCALBASE}/share/icons/Numix-Light)
	(cd ${WRKSRC_apps}/Numix-Circle && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LOCALBASE}/share/icons/Numix)
	(cd ${WRKSRC_apps}/Numix-Circle-Light && ${COPYTREE_SHARE} . \
		${STAGEDIR}${LOCALBASE}/share/icons/Numix-Light)

.include <bsd.port.mk>
