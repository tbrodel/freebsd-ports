--- libs/ptformat/ptfformat.cc.orig	2016-02-19 01:28:56 UTC
+++ libs/ptformat/ptfformat.cc
@@ -17,6 +17,9 @@
 #include "ptfformat.h"
 
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#endif
 #include <string>
 #include <string.h>
 #include <assert.h>
