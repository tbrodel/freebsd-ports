--- server/plugins/UIUGens.cpp.orig	2016-02-16 01:19:22 UTC
+++ server/plugins/UIUGens.cpp
@@ -416,13 +416,13 @@ void cmdDemoFunc(World *inWorld, void* i
  */
 
 
-thread uiListenThread;
+std::thread uiListenThread;
 
 PluginLoad(UIUGens)
 {
 	ft = inTable;
 
-	thread thread( gstate_update_func );
+	std::thread thread( gstate_update_func );
 	uiListenThread = std::move(thread);
 	uiListenThread.detach();
 
