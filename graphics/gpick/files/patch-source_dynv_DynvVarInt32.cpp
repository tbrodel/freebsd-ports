--- source/dynv/DynvVarInt32.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarInt32.cpp
@@ -22,48 +22,49 @@
 #include "../Endian.h"
 
 #include <sstream>
-using namespace std;
 
-static int dynv_var_int32_create(struct dynvVariable* variable){
+static int dynv_var_int32_create(struct dynvVariable* variable)
+{
 	variable->int_value = 0;
 	return 0;
 }
 
-static int dynv_var_int32_destroy(struct dynvVariable* variable){
+static int dynv_var_int32_destroy(struct dynvVariable* variable)
+{
 	return 0;
 }
 
-static int dynv_var_int32_set(struct dynvVariable* variable, void* value, bool deref){
+static int dynv_var_int32_set(struct dynvVariable* variable, void* value, bool deref)
+{
 	variable->int_value = *((int32_t*)value);
 	return 0;
 }
 
-static int dynv_var_int32_get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_int32_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	*value = &variable->int_value;
 	return 0;
 }
 
-static int dynv_var_int32_serialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_int32_serialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	uint32_t written;
-
-	uint32_t length=4;
+	uint32_t length = 4;
 	length = UINT32_TO_LE(length);
-
 	dynv_io_write(io, &length, 4, &written);
-
 	int32_t value = UINT32_TO_LE(variable->int_value);
-	if (dynv_io_write(io, &value, 4, &written)==0){
+	if (dynv_io_write(io, &value, 4, &written) == 0){
 		if (written == 4) return 0;
 	}
 	return -1;
 }
 
-static int dynv_var_int32_deserialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_int32_deserialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	uint32_t read;
 	int32_t value;
 	dynv_io_read(io, &value, 4, &read);
-
-	if (dynv_io_read(io, &value, 4, &read)==0){
+	if (dynv_io_read(io, &value, 4, &read) == 0){
 		if (read == 4){
 			variable->int_value = UINT32_FROM_LE(value);
 			return 0;
@@ -72,33 +73,32 @@ static int dynv_var_int32_deserialize(st
 	return -1;
 }
 
-static int serialize_xml(struct dynvVariable* variable, ostream& out){
+static int serialize_xml(struct dynvVariable* variable, std::ostream& out)
+{
 	out << variable->int_value;
 	return 0;
 }
 
-static int deserialize_xml(struct dynvVariable* variable, const char *data){
-	stringstream ss(stringstream::in);
+static int deserialize_xml(struct dynvVariable* variable, const char *data)
+{
+	std::stringstream ss(std::stringstream::in);
 	ss.str(data);
 	ss >> variable->int_value;
 	return 0;
 }
 
-struct dynvHandler* dynv_var_int32_new(){
-	struct dynvHandler* handler=dynv_handler_create("int32");
-
-	handler->create=dynv_var_int32_create;
-	handler->destroy=dynv_var_int32_destroy;
-	handler->set=dynv_var_int32_set;
-	handler->get=dynv_var_int32_get;
-	handler->serialize=dynv_var_int32_serialize;
-	handler->deserialize=dynv_var_int32_deserialize;
-
+struct dynvHandler* dynv_var_int32_new()
+{
+	struct dynvHandler* handler = dynv_handler_create("int32");
+	handler->create = dynv_var_int32_create;
+	handler->destroy = dynv_var_int32_destroy;
+	handler->set = dynv_var_int32_set;
+	handler->get = dynv_var_int32_get;
+	handler->serialize = dynv_var_int32_serialize;
+	handler->deserialize = dynv_var_int32_deserialize;
 	handler->serialize_xml = serialize_xml;
 	handler->deserialize_xml = deserialize_xml;
-
 	handler->data_size = sizeof(int32_t);
-
 	return handler;
 }
 
