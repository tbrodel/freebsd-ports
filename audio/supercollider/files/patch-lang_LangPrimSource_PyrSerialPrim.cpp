--- lang/LangPrimSource/PyrSerialPrim.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangPrimSource/PyrSerialPrim.cpp
@@ -145,7 +145,7 @@ private:
 
 	// rx thread
 	std::atomic<bool>	m_running;
-	thread				m_thread;
+	std::thread				m_thread;
 };
 
 PyrSymbol* SerialPort::s_dataAvailable = 0;
@@ -340,7 +340,7 @@ SerialPort::SerialPort(PyrObject* obj, c
 	m_rxErrors[0] = m_rxErrors[1] = 0;
 
 	try {
-		thread thread(std::bind(&SerialPort::threadLoop, this));
+		std::thread thread(std::bind(&SerialPort::threadLoop, this));
 		m_thread = std::move(thread);
 	} catch(std::exception & e) {
 		close(m_fd);
