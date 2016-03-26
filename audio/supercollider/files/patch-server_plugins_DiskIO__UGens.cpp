--- server/plugins/DiskIO_UGens.cpp.orig	2016-02-16 01:19:22 UTC
+++ server/plugins/DiskIO_UGens.cpp
@@ -129,7 +129,7 @@ void DiskIOMsg::Perform()
 			if (count < mFrames) {
 				memset(buf->data + (mPos + count) * buf->channels, 0, (mFrames - count) * buf->channels * sizeof(float));
 				World_GetBuf(mWorld, mBufNum)->mask = mPos + count;
-				// NOTE: Possible race condition above: The disk IO thread may write to the rt SndBuf
+				// NOTE: Possible race condition above: The disk IO std::thread may write to the rt SndBuf
 				// while the stage3 of the sequenced commands copies the non-rt SndBuf struct to the rt buf.
 				// This only happens if the buffer is modified via an osc command.
 				// We can't use the non-rt SndBuf above since buf->mask won't be reflected to the rt buf.
@@ -168,7 +168,7 @@ struct DiskIOThread
 #endif
 
 	std::atomic<bool> mRunning;
-	thread mThread;
+	std::thread mThread;
 
 	DiskIOThread():
 		mRunning(false)
@@ -188,7 +188,7 @@ struct DiskIOThread
 		using namespace std;
 		mRunning.store(true);
 
-		mThread = move( thread( bind(&DiskIOThread::ioThreadFunc, this) ) );
+		mThread = move( std::thread( bind(&DiskIOThread::ioThreadFunc, this) ) );
 	}
 
 	bool Write(DiskIOMsg& data)
