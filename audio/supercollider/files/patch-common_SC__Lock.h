--- common/SC_Lock.h.orig	2016-02-16 01:23:34 UTC
+++ common/SC_Lock.h
@@ -34,7 +34,6 @@ using std::lock_guard;
 using std::unique_lock;
 using std::cv_status;
 typedef std::condition_variable_any condition_variable_any;
-using std::thread;
 
 typedef SC_Lock mutex;
 
