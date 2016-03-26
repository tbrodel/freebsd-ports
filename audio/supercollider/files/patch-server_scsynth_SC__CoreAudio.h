--- server/scsynth/SC_CoreAudio.h.orig	2016-02-16 01:19:22 UTC
+++ server/scsynth/SC_CoreAudio.h
@@ -71,12 +71,12 @@
 
 struct SC_ScheduledEvent
 {
-	/// Callback function responsible for freeing the OSC packet in the correct thread.
+	/// Callback function responsible for freeing the OSC packet in the correct std::thread.
 	typedef void (*PacketFreeFunc)(struct World* world, OSC_Packet* packet);
 
-	/// Frees an OSC packet in the realtime thread (to be used as a PacketFreeFunc).
+	/// Frees an OSC packet in the realtime std::thread (to be used as a PacketFreeFunc).
 	static void FreeInRT(struct World* world, OSC_Packet* packet);
-	/// Frees an OSC packet in the non-realtime thread (to be used as a PacketFreeFunc).
+	/// Frees an OSC packet in the non-realtime std::thread (to be used as a PacketFreeFunc).
 	static void FreeInNRT(struct World* world, OSC_Packet* packet);
 
 	SC_ScheduledEvent() : mTime(0), mPacket(0) {}
@@ -149,7 +149,7 @@ enum PacketStatus
 	PacketScheduled
 };
 
-/** Perform a completion message in the realtime thread.
+/** Perform a completion message in the realtime std::thread.
 
 	The return value denotes whether ownership is transferred to the scheduler or not.
  */
@@ -168,7 +168,7 @@ protected:
 	EngineFifo mFromEngine, mToEngine;
 	EngineFifo mOscPacketsToEngine;
 	SC_SyncCondition mAudioSync;
-	thread mThread;
+	std::thread mThread;
 	bool mRunThreadFlag;
 	uint32 mSafetyOffset;
 	PriorityQueueT<SC_ScheduledEvent, 2048> mScheduler;
@@ -234,7 +234,7 @@ public:
 		mPreferredSampleRate = inRate;
 	}
 
-	bool SendMsgToEngine(FifoMsg& inMsg);           // called by NRT thread
+	bool SendMsgToEngine(FifoMsg& inMsg);           // called by NRT std::thread
 	bool SendMsgFromEngine(FifoMsg& inMsg);
 	bool SendOscPacketMsgToEngine(FifoMsg& inMsg);  // called by OSC socket listener threads, protected by mWorld->mDriverLock
 
