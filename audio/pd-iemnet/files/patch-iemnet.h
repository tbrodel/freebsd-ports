--- iemnet.h.orig	2016-02-10 03:04:51 UTC
+++ iemnet.h
@@ -51,6 +51,9 @@ EXTERN void sys_rmpollfn(int fd);
 # include <arpa/inet.h>
 # include <sys/socket.h>
 #endif
+#ifdef __FreeBSD__
+# include <netinet/in.h>
+#endif
 #include <sys/types.h>
 
 /* iemnet_data.c */
