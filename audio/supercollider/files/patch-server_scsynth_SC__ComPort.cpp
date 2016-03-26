--- server/scsynth/SC_ComPort.cpp.orig	2016-02-16 01:19:22 UTC
+++ server/scsynth/SC_ComPort.cpp
@@ -147,7 +147,7 @@ static bool UnrollOSCPacket(World *inWor
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////
 
-thread gAsioThread;
+std::thread gAsioThread;
 boost::asio::io_service ioService;
 
 const int kTextBufSize = 65536;
@@ -204,7 +204,7 @@ class SC_UdpInPort
 	boost::asio::ip::udp::endpoint remoteEndpoint;
 
 #ifdef USE_RENDEZVOUS
-	thread mRendezvousThread;
+	std::thread mRendezvousThread;
 #endif
 
 	void handleReceivedUDP(const boost::system::error_code& error,
@@ -263,7 +263,7 @@ public:
 
 #ifdef USE_RENDEZVOUS
 		if (world->mRendezvous) {
-			thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_UDP, sc_htons(mPortNum) ) );
+			std::thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_UDP, sc_htons(mPortNum) ) );
 			mRendezvousThread = std::move(thread);
 		}
 #endif
@@ -393,7 +393,7 @@ class SC_TcpInPort
 	boost::asio::ip::tcp::acceptor acceptor;
 
 #ifdef USE_RENDEZVOUS
-	thread mRendezvousThread;
+	std::thread mRendezvousThread;
 #endif
 
 	std::atomic<int> mAvailableConnections;
@@ -409,7 +409,7 @@ public:
 
 #ifdef USE_RENDEZVOUS
 		if (world->mRendezvous) {
-			thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_TCP, sc_htons(inPortNum) ) );
+			std::thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_TCP, sc_htons(inPortNum) ) );
 			mRendezvousThread = std::move(thread);
 		}
 #endif
@@ -470,7 +470,7 @@ static void asioFunction()
 
 void startAsioThread()
 {
-	thread asioThread (&asioFunction);
+	std::thread asioThread (&asioFunction);
 	gAsioThread = std::move(asioThread);
 }
 
