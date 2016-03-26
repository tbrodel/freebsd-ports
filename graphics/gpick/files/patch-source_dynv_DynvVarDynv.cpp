--- source/dynv/DynvVarDynv.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarDynv.cpp
@@ -24,14 +24,15 @@
 #include "../Endian.h"
 
 #include <iostream>
-using namespace std;
 
-static int create(struct dynvVariable* variable){
+static int dynv_var_dynv_create(struct dynvVariable* variable)
+{
 	variable->ptr_value = 0;
 	return 0;
 }
 
-static int destroy(struct dynvVariable* variable){
+static int dynv_var_dynv_destroy(struct dynvVariable* variable)
+{
 	if (variable->ptr_value){
 		dynv_system_release((struct dynvSystem*)variable->ptr_value);
 		return 0;
@@ -39,8 +40,9 @@ static int destroy(struct dynvVariable* 
 	return -1;
 }
 
-static int set(struct dynvVariable* variable, void* value, bool deref){
-	if (variable->ptr_value) dynv_system_release((struct dynvSystem*)variable->ptr_value);
+static int dynv_var_dynv_set(struct dynvVariable* variable, void* value, bool deref)
+{
+	if (variable->ptr_value)dynv_system_release((struct dynvSystem*)variable->ptr_value);
 	if (deref)
 		variable->ptr_value = dynv_system_ref(*((struct dynvSystem**)value));
 	else
@@ -48,35 +50,33 @@ static int set(struct dynvVariable* vari
 	return 0;
 }
 
-static int get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_dynv_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	if (variable->ptr_value){
-		*value= dynv_system_ref((struct dynvSystem*)variable->ptr_value);
+		*value = dynv_system_ref((struct dynvSystem*)variable->ptr_value);
 		*deref = false;
 		return 0;
 	}
 	return -1;
 }
 
-static int serialize_xml(struct dynvVariable* variable, ostream& out){
+static int dynv_var_dynv_serialize_xml(struct dynvVariable* variable, std::ostream& out)
+{
 	if (variable->ptr_value){
-		out << endl;
+		out << std::endl;
 		dynv_xml_serialize((struct dynvSystem*)variable->ptr_value, out);
 	}
 	return 0;
 }
 
-struct dynvHandler* dynv_var_dynv_new(){
-	struct dynvHandler* handler=dynv_handler_create("dynv");
-
-	handler->create=create;
-	handler->destroy=destroy;
-	handler->set=set;
-	handler->get=get;
-	//handler->serialize=serialize;
-	//handler->deserialize=deserialize;
-
-	handler->serialize_xml = serialize_xml;
-
+struct dynvHandler* dynv_var_dynv_new()
+{
+	struct dynvHandler* handler = dynv_handler_create("dynv");
+	handler->create = dynv_var_dynv_create;
+	handler->destroy = dynv_var_dynv_destroy;
+	handler->set = dynv_var_dynv_set;
+	handler->get = dynv_var_dynv_get;
+	handler->serialize_xml = dynv_var_dynv_serialize_xml;
 	handler->data_size = sizeof(struct dynvSystem*);
 	return handler;
 }
