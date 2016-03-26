--- QtCollider/QObjectProxy.cpp.orig	2016-02-16 01:44:18 UTC
+++ QtCollider/QObjectProxy.cpp
@@ -38,6 +38,8 @@
 
 #ifdef _WIN32
 # include "SC_Win32Utils.h"
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif
