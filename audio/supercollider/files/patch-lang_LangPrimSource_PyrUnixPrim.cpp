--- lang/LangPrimSource/PyrUnixPrim.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangPrimSource/PyrUnixPrim.cpp
@@ -179,7 +179,7 @@ int prString_POpen(struct VMGlobals *g, 
 		return errFailed;
 	}
 
-	thread thread(std::bind(string_popen_thread_func, process));
+	std::thread thread(std::bind(string_popen_thread_func, process));
 	thread.detach();
 
 	SetInt(a, process->pid);
