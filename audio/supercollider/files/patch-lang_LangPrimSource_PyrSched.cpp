--- lang/LangPrimSource/PyrSched.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangPrimSource/PyrSched.cpp
@@ -207,8 +207,8 @@ void dumpheap(PyrObject *heapArg)
 
 
 bool gRunSched = false;
-thread gSchedThread;
-thread gResyncThread;
+std::thread gSchedThread;
+std::thread gResyncThread;
 condition_variable_any gSchedCond;
 timed_mutex gLangMutex;
 
@@ -246,7 +246,7 @@ SCLANG_DLLEXPORT_C void schedInit()
 	hrTimeOfInitialization     = high_resolution_clock::now();
 
 	syncOSCOffsetWithTimeOfDay();
-	thread thread(resyncThread);
+	std::thread thread(resyncThread);
 	gResyncThread = std::move(thread);
 
 	gHostStartNanos = duration_cast<nanoseconds>(hrTimeOfInitialization.time_since_epoch()).count();
@@ -595,7 +595,7 @@ static void SC_LinuxSetRealtimePriority(
 
 SCLANG_DLLEXPORT_C void schedRun()
 {
-	thread thread(schedRunFunc);
+	std::thread thread(schedRunFunc);
 	gSchedThread = std::move(thread);
 
 #ifdef __APPLE__
@@ -699,7 +699,7 @@ public:
 	double mBaseSeconds;
 	double mBaseBeats;
 	bool mRun;
-	thread mThread;
+	std::thread mThread;
 	condition_variable_any mCondition;
 	TempoClock *mPrev, *mNext;
 
@@ -736,7 +736,7 @@ TempoClock::TempoClock(VMGlobals *inVMGl
 	mQueue->size = 1;
 	SetInt(&mQueue->count, 0);
 
-	thread thread(std::bind(&TempoClock::Run, this));
+	std::thread thread(std::bind(&TempoClock::Run, this));
 	mThread = std::move(thread);
 
 #ifdef __APPLE__
@@ -764,7 +764,7 @@ TempoClock::TempoClock(VMGlobals *inVMGl
 void TempoClock::StopReq()
 {
 	//printf("->TempoClock::StopReq\n");
-	thread stopThread(std::bind(&TempoClock::StopAndDelete, this));
+	std::thread stopThread(std::bind(&TempoClock::StopAndDelete, this));
 	stopThread.detach();
 
 	//printf("<-TempoClock::StopReq\n");
