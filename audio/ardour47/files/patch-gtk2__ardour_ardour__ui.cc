--- gtk2_ardour/ardour_ui.cc.orig	2016-02-19 01:28:56 UTC
+++ gtk2_ardour/ardour_ui.cc
@@ -33,6 +33,10 @@
 #include <sys/resource.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 #include <stdint.h>
 #include <fcntl.h>
 #include <signal.h>
