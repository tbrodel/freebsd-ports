--- lang/LangSource/SC_TerminalClient.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangSource/SC_TerminalClient.cpp
@@ -625,7 +625,7 @@ void SC_TerminalClient::initInput()
 
 void SC_TerminalClient::startInput()
 {
-	thread thread(std::bind(&SC_TerminalClient::inputThreadFn, this));
+	std::thread thread(std::bind(&SC_TerminalClient::inputThreadFn, this));
 	mInputThread = std::move(thread);
 }
 
