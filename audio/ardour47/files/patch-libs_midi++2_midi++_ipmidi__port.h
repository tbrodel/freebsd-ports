--- libs/midi++2/midi++/ipmidi_port.h.orig	2016-02-19 01:28:56 UTC
+++ libs/midi++2/midi++/ipmidi_port.h
@@ -23,7 +23,7 @@
 #include <iostream>
 #if defined(PLATFORM_WINDOWS)
 #include <winsock.h>
-#elif defined(__FREE_BSD__)
+#elif defined(__FreeBSD__)
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/_sockaddr_storage.h>
