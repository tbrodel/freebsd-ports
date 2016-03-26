--- lang/LangSource/SC_LanguageClient.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangSource/SC_LanguageClient.cpp
@@ -137,7 +137,7 @@ void SC_LanguageClient::initRuntime(cons
 }
 
 
-extern thread gResyncThread;
+extern std::thread gResyncThread;
 
 void SC_LanguageClient::shutdownRuntime()
 {
