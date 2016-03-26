--- lang/LangSource/SC_TerminalClient.h.orig	2016-02-16 01:19:21 UTC
+++ lang/LangSource/SC_TerminalClient.h
@@ -39,7 +39,7 @@
 // SC_TerminalClient - command line sclang client.
 // =====================================================================
 
-// TODO: move locks & thread out of the header, possibly using pimpl
+// TODO: move locks & std::thread out of the header, possibly using pimpl
 class SCLANG_DLLEXPORT SC_TerminalClient : public SC_LanguageClient
 {
 public:
@@ -92,8 +92,8 @@ public:
 	virtual void postError(const char* str, size_t len);
 	virtual void flush();
 
-	// Requests an action to be taken on the main thread.
-	// NOTE: It may be called from any thread, and with interpreter locked.
+	// Requests an action to be taken on the main std::thread.
+	// NOTE: It may be called from any std::thread, and with interpreter locked.
 	virtual void sendSignal( Signal code );
 
 	void stop()
@@ -110,14 +110,14 @@ protected:
 
 	// --------------------------------------------------------------
 
-	// NOTE: Subclasses should call from main thread
+	// NOTE: Subclasses should call from main std::thread
 	// after receiving sig_input
 	void interpretInput();
 
 	// --------------------------------------------------------------
 
 	// Language requested the application to quit
-	// NOTE: It may be called from any thread, and with interpreter locked.
+	// NOTE: It may be called from any std::thread, and with interpreter locked.
 	virtual void onQuit( int exitCode );
 
 	// See super class
@@ -139,7 +139,7 @@ protected:
 	void tick(const boost::system::error_code& error);
 
 private:
-	// NOTE: called from input thread:
+	// NOTE: called from input std::thread:
 #ifdef HAVE_READLINE
 	static void readlineInit();
 	static void readlineFunc(SC_TerminalClient *);
@@ -166,7 +166,7 @@ private:
 
 	// input io service
 	boost::asio::io_service mInputService;
-	thread mInputThread;
+	std::thread mInputThread;
 	void inputThreadFn();
 
 	static const size_t inputBufferSize = 256;
