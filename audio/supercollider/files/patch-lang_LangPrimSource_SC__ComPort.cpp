--- lang/LangPrimSource/SC_ComPort.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangPrimSource/SC_ComPort.cpp
@@ -44,7 +44,7 @@ void ProcessOSCPacket(OSC_Packet *inPack
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////
 
-thread gAsioThread;
+std::thread gAsioThread;
 boost::asio::io_service ioService;
 
 
@@ -56,7 +56,7 @@ static void asioFunction()
 
 void startAsioThread()
 {
-	thread asioThread (&asioFunction);
+	std::thread asioThread (&asioFunction);
 	gAsioThread = std::move(asioThread);
 }
 
