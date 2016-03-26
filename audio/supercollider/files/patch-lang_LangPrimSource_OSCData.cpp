--- lang/LangPrimSource/OSCData.cpp.orig	2016-02-16 01:33:55 UTC
+++ lang/LangPrimSource/OSCData.cpp
@@ -1037,9 +1037,9 @@ int prQuitInProcessServer(VMGlobals *g, 
 		World *world = gInternalSynthServer.mWorld;
 		gInternalSynthServer.mWorld = 0;
 
-		thread thread(std::bind(World_WaitForQuit, world, false));
+		std::thread thread(std::bind(World_WaitForQuit, world, false));
 
		thread.detach();
 	}
 
 	return errNone;
