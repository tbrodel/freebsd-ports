--- lang/LangSource/PyrObject.cpp.orig	2016-02-16 01:19:21 UTC
+++ lang/LangSource/PyrObject.cpp
@@ -856,7 +856,7 @@ static PyrClass * sortClasses(PyrClass *
 
 #include <boost/threadpool.hpp>
 
-static int cpuCount = thread::hardware_concurrency();
+static int cpuCount = std::thread::hardware_concurrency();
 static int helperThreadCount = cpuCount - 1;
 static boost::threadpool::fifo_pool compileThreadPool;
 
