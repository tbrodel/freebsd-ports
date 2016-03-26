--- source/dynv/DynvVarPtr.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarPtr.cpp
@@ -21,36 +21,36 @@
 #include "DynvIO.h"
 #include "../Endian.h"
 
-static int dynv_var_ptr_create(struct dynvVariable* variable){
+static int dynv_var_ptr_create(struct dynvVariable* variable)
+{
 	variable->ptr_value = 0;
 	return 0;
 }
 
-static int dynv_var_ptr_destroy(struct dynvVariable* variable){
+static int dynv_var_ptr_destroy(struct dynvVariable* variable)
+{
 	return 0;
 }
 
-static int dynv_var_ptr_set(struct dynvVariable* variable, void* value, bool deref){
+static int dynv_var_ptr_set(struct dynvVariable* variable, void* value, bool deref)
+{
 	variable->ptr_value = *(void**)value;
 	return 0;
 }
 
-static int dynv_var_ptr_get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_ptr_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	*value = &variable->ptr_value;
 	return 0;
 }
 
 struct dynvHandler* dynv_var_ptr_new(){
-	struct dynvHandler* handler=dynv_handler_create("ptr");
-
-	handler->create=dynv_var_ptr_create;
-	handler->destroy=dynv_var_ptr_destroy;
-	handler->set=dynv_var_ptr_set;
-	handler->get=dynv_var_ptr_get;
-	handler->serialize=0;
-	handler->deserialize=0;
-
+	struct dynvHandler* handler = dynv_handler_create("ptr");
+	handler->create = dynv_var_ptr_create;
+	handler->destroy = dynv_var_ptr_destroy;
+	handler->set = dynv_var_ptr_set;
+	handler->get = dynv_var_ptr_get;
 	handler->data_size = sizeof(void*);
-
 	return handler;
 }
+
