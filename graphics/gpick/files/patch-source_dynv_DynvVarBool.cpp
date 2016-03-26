--- source/dynv/DynvVarBool.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarBool.cpp
@@ -25,28 +25,32 @@
 #include <stdlib.h>
 
 #include <iostream>
-using namespace std;
 
-static int create(struct dynvVariable* variable){
+static int dynv_var_bool_create(struct dynvVariable* variable)
+{
 	variable->bool_value = false;
 	return 0;
 }
 
-static int destroy(struct dynvVariable* variable){
+static int dynv_var_bool_destroy(struct dynvVariable* variable)
+{
 	return 0;
 }
 
-static int set(struct dynvVariable* variable, void* value, bool deref){
+static int dynv_var_bool_set(struct dynvVariable* variable, void* value, bool deref)
+{
 	variable->bool_value = *(bool*)value;
 	return 0;
 }
 
-static int get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_bool_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	*value = &variable->bool_value;
 	return 0;
 }
 
-static int serialize_xml(struct dynvVariable* variable, ostream& out){
+static int dynv_var_bool_serialize_xml(struct dynvVariable* variable, std::ostream& out)
+{
 	if (variable->bool_value){
 		out << "true";
 	}else{
@@ -55,8 +59,9 @@ static int serialize_xml(struct dynvVari
 	return 0;
 }
 
-static int deserialize_xml(struct dynvVariable* variable, const char *data){
-	if (strcmp(data, "true")==0){
+static int dynv_var_bool_deserialize_xml(struct dynvVariable* variable, const char *data)
+{
+	if (strcmp(data, "true") == 0){
 		*(bool*)&variable->bool_value = true;
 	}else{
 		*(bool*)&variable->bool_value = false;
@@ -64,21 +69,16 @@ static int deserialize_xml(struct dynvVa
 	return 0;
 }
 
-struct dynvHandler* dynv_var_bool_new(){
+struct dynvHandler* dynv_var_bool_new()
+{
 	struct dynvHandler* handler=dynv_handler_create("bool");
-
-	handler->create=create;
-	handler->destroy=destroy;
-	handler->set=set;
-	handler->get=get;
-	//handler->serialize=serialize;
-	//handler->deserialize=deserialize;
-
-	handler->serialize_xml = serialize_xml;
-	handler->deserialize_xml = deserialize_xml;
-
+	handler->create = dynv_var_bool_create;
+	handler->destroy = dynv_var_bool_destroy;
+	handler->set = dynv_var_bool_set;
+	handler->get = dynv_var_bool_get;
+	handler->serialize_xml = dynv_var_bool_serialize_xml;
+	handler->deserialize_xml = dynv_var_bool_deserialize_xml;
 	handler->data_size = sizeof(bool);
-
 	return handler;
 }
 
