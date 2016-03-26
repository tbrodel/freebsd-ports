--- source/dynv/DynvVarString.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarString.cpp
@@ -23,14 +23,14 @@
 #include "../Endian.h"
 #include <string.h>
 
-using namespace std;
-
-static int dynv_var_string_create(struct dynvVariable* variable){
+static int dynv_var_string_create(struct dynvVariable* variable)
+{
 	variable->ptr_value = 0;
 	return -1;
 }
 
-static int dynv_var_string_destroy(struct dynvVariable* variable){
+static int dynv_var_string_destroy(struct dynvVariable* variable)
+{
 	if (variable->ptr_value){
 		delete [] (char*)variable->ptr_value;
 		return 0;
@@ -38,18 +38,19 @@ static int dynv_var_string_destroy(struc
 	return -1;
 }
 
-static int dynv_var_string_set(struct dynvVariable* variable, void* value, bool deref){
+static int dynv_var_string_set(struct dynvVariable* variable, void* value, bool deref)
+{
 	if (variable->ptr_value){
 		delete [] (char*)variable->ptr_value;
 	}
-
 	uint32_t len = strlen(*(char**)value)+1;
 	variable->ptr_value = new char [len];
 	memcpy(variable->ptr_value, *(void**)value, len);
 	return 0;
 }
 
-static int dynv_var_string_get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_string_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	if (variable->ptr_value){
 		*value = &variable->ptr_value;
 		return 0;
@@ -57,20 +58,18 @@ static int dynv_var_string_get(struct dy
 	return -1;
 }
 
-static int dynv_var_string_serialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_string_serialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	if (!variable->ptr_value) return -1;
 	uint32_t written;
 	uint32_t length = strlen((char*)variable->ptr_value);
 	uint32_t length_le = UINT32_TO_LE(length);
-
-	if (dynv_io_write(io, &length_le, 4, &written)==0){
+	if (dynv_io_write(io, &length_le, 4, &written) == 0){
 		if (written != 4) return -1;
 	}else return -1;
-
-	if (dynv_io_write(io, variable->ptr_value, length, &written)==0){
+	if (dynv_io_write(io, variable->ptr_value, length, &written) == 0){
 		if (written != length) return -1;
 	}else return -1;
-
 	return 0;
 }
 
@@ -81,58 +80,50 @@ static int dynv_var_string_deserialize(s
 	}
 	uint32_t read;
 	uint32_t length;
-
-	if (dynv_io_read(io, &length, 4, &read)==0){
+	if (dynv_io_read(io, &length, 4, &read) == 0){
 		if (read != 4) return -1;
 	}else return -1;
-
 	length = UINT32_FROM_LE(length);
-
 	variable->ptr_value = new char [length+1];
-
-	if (dynv_io_read(io, variable->ptr_value, length, &read)==0){
+	if (dynv_io_read(io, variable->ptr_value, length, &read) == 0){
 		if (read != length) return -1;
 	}else return -1;
-
 	((char*)variable->ptr_value)[length] = 0;
-
 	return 0;
 }
 
-static int serialize_xml(struct dynvVariable* variable, ostream& out){
+static int serialize_xml(struct dynvVariable* variable, std::ostream& out)
+{
 	if (variable->ptr_value){
-		//out << (char*)variable->value;
 		dynv_xml_escape((char*)variable->ptr_value, out);
 	}
 	return 0;
 }
 
-static int deserialize_xml(struct dynvVariable* variable, const char *data){
+static int deserialize_xml(struct dynvVariable* variable, const char *data)
+{
 	if (variable->ptr_value){
 		delete [] (char*)variable->ptr_value;
 		variable->ptr_value = 0;
 	}
-	uint32_t len = strlen(data)+1;
-	variable->ptr_value = new char [len];
+	uint32_t len = strlen(data) + 1;
+	variable->ptr_value = new char[len];
 	memcpy(variable->ptr_value, data, len);
 	return 0;
 }
 
-struct dynvHandler* dynv_var_string_new(){
-	struct dynvHandler* handler=dynv_handler_create("string");
-
-	handler->create=dynv_var_string_create;
-	handler->destroy=dynv_var_string_destroy;
-	handler->set=dynv_var_string_set;
-	handler->get=dynv_var_string_get;
-	handler->serialize=dynv_var_string_serialize;
-	handler->deserialize=dynv_var_string_deserialize;
-
-	handler->serialize_xml=serialize_xml;
+struct dynvHandler* dynv_var_string_new()
+{
+	struct dynvHandler* handler = dynv_handler_create("string");
+	handler->create = dynv_var_string_create;
+	handler->destroy = dynv_var_string_destroy;
+	handler->set = dynv_var_string_set;
+	handler->get = dynv_var_string_get;
+	handler->serialize = dynv_var_string_serialize;
+	handler->deserialize = dynv_var_string_deserialize;
+	handler->serialize_xml = serialize_xml;
 	handler->deserialize_xml=deserialize_xml;
-
 	handler->data_size = sizeof(char*);
-
 	return handler;
 }
 
