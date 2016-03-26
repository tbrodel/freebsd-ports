--- libs/midi++2/ipmidi_port.cc.orig	2016-02-19 01:28:56 UTC
+++ libs/midi++2/ipmidi_port.cc
@@ -36,6 +36,10 @@
 #include <netdb.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#endif
+
 #if defined(PLATFORM_WINDOWS)
 typedef int socklen_t;
 #else
