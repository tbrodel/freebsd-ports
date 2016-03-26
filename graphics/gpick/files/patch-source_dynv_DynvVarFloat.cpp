--- source/dynv/DynvVarFloat.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarFloat.cpp
@@ -22,28 +22,32 @@
 #include "../Endian.h"
 
 #include <sstream>
-using namespace std;
 
-static int dynv_var_float_create(struct dynvVariable* variable){
+static int dynv_var_float_create(struct dynvVariable* variable)
+{
 	variable->float_value = 0;
 	return 0;
 }
 
-static int dynv_var_float_destroy(struct dynvVariable* variable){
+static int dynv_var_float_destroy(struct dynvVariable* variable)
+{
 	return 0;
 }
 
-static int dynv_var_float_set(struct dynvVariable* variable, void* value, bool deref){
+static int dynv_var_float_set(struct dynvVariable* variable, void* value, bool deref)
+{
 	variable->float_value = *((float*)value);
 	return 0;
 }
 
-static int dynv_var_float_get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_float_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	*value = &variable->float_value;
 	return 0;
 }
 
-static int dynv_var_float_serialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_float_serialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	uint32_t written;
 
 	uint32_t length = 4;
@@ -64,17 +68,16 @@ static int dynv_var_float_serialize(stru
 	return -1;
 }
 
-static int dynv_var_float_deserialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_float_deserialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	uint32_t read;
 	uint32_t size;
 	dynv_io_read(io, &size, 4, &read);
-
-    union{
+	union{
 		uint32_t i32;
 		float f32;
 	}value;
-
-    if (dynv_io_read(io, &value, 4, &read)==0){
+	if (dynv_io_read(io, &value, 4, &read) == 0){
 		if (read == 4){
 			value.i32 = UINT32_FROM_LE(value.i32);
 			variable->float_value = value.f32;
@@ -84,32 +87,32 @@ static int dynv_var_float_deserialize(st
 	return -1;
 }
 
-static int serialize_xml(struct dynvVariable* variable, ostream& out){
+static int serialize_xml(struct dynvVariable* variable, std::ostream& out)
+{
 	out << variable->float_value;
 	return 0;
 }
 
-static int deserialize_xml(struct dynvVariable* variable, const char *data){
-	stringstream ss(stringstream::in);
+static int deserialize_xml(struct dynvVariable* variable, const char *data)
+{
+	std::stringstream ss(std::stringstream::in);
 	ss.str(data);
 	ss >> variable->float_value;
 	return 0;
 }
 
-struct dynvHandler* dynv_var_float_new(){
+struct dynvHandler* dynv_var_float_new()
+{
 	struct dynvHandler* handler=dynv_handler_create("float");
-
-	handler->create=dynv_var_float_create;
-	handler->destroy=dynv_var_float_destroy;
-	handler->set=dynv_var_float_set;
-	handler->get=dynv_var_float_get;
-	handler->serialize=dynv_var_float_serialize;
-	handler->deserialize=dynv_var_float_deserialize;
+	handler->create = dynv_var_float_create;
+	handler->destroy = dynv_var_float_destroy;
+	handler->set = dynv_var_float_set;
+	handler->get = dynv_var_float_get;
+	handler->serialize = dynv_var_float_serialize;
+	handler->deserialize = dynv_var_float_deserialize;
 	handler->serialize_xml = serialize_xml;
 	handler->deserialize_xml = deserialize_xml;
-
 	handler->data_size = sizeof(float);
-
 	return handler;
 }
 
