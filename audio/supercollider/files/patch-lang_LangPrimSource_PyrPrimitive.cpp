--- lang/LangPrimSource/PyrPrimitive.cpp.orig	2016-02-16 01:52:17 UTC
+++ lang/LangPrimSource/PyrPrimitive.cpp
@@ -4247,7 +4247,7 @@ void initMIDIPrimitives();
 	initMIDIPrimitives();
 #endif
 
-#if !defined(_WIN32) && !defined(SC_IPHONE) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(SC_IPHONE) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 void initLIDPrimitives();
 	initLIDPrimitives();
 #endif
