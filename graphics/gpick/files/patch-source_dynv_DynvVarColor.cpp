--- source/dynv/DynvVarColor.cpp.orig	2013-02-28 17:34:31 UTC
+++ source/dynv/DynvVarColor.cpp
@@ -23,16 +23,17 @@
 #include <string.h>
 
 #include <sstream>
-using namespace std;
 
-static int dynv_var_color_create(struct dynvVariable* variable){
+static int dynv_var_color_create(struct dynvVariable* variable)
+{
 	if ((variable->ptr_value = new float[4])){
 		return 0;
 	}
 	return -1;
 }
 
-static int dynv_var_color_destroy(struct dynvVariable* variable){
+static int dynv_var_color_destroy(struct dynvVariable* variable)
+{
 	if (variable->ptr_value){
 		delete [] (float*)variable->ptr_value;
 		return 0;
@@ -40,18 +41,15 @@ static int dynv_var_color_destroy(struct
 	return -1;
 }
 
-static int dynv_var_color_set(struct dynvVariable* variable, void* value, bool deref){
+static int dynv_var_color_set(struct dynvVariable* variable, void* value, bool deref)
+{
 	if (!variable->ptr_value) return -1;
 	memcpy(variable->ptr_value, *(void**)value, sizeof(float[4]));
-
-	/*((float*)variable->ptr_value)[0] = ((float*)value)[0];
-	((float*)variable->ptr_value)[1] = ((float*)value)[1];
-	((float*)variable->ptr_value)[2] = ((float*)value)[2];
-	((float*)variable->ptr_value)[3] = ((float*)value)[3];*/
 	return 0;
 }
 
-static int dynv_var_color_get(struct dynvVariable* variable, void** value, bool *deref){
+static int dynv_var_color_get(struct dynvVariable* variable, void** value, bool *deref)
+{
 	if (variable->ptr_value){
 		*value = &variable->ptr_value;
 		return 0;
@@ -59,7 +57,8 @@ static int dynv_var_color_get(struct dyn
 	return -1;
 }
 
-static int dynv_var_color_serialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_color_serialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	if (!variable->ptr_value) return -1;
 	uint32_t written;
 
@@ -81,7 +80,8 @@ static int dynv_var_color_serialize(stru
 	return 0;
 }
 
-static int dynv_var_color_deserialize(struct dynvVariable* variable, struct dynvIO* io){
+static int dynv_var_color_deserialize(struct dynvVariable* variable, struct dynvIO* io)
+{
 	if (!variable->ptr_value) return -1;
 
 	uint32_t read;
@@ -102,7 +102,8 @@ static int dynv_var_color_deserialize(st
 	return -1;
 }
 
-static int serialize_xml(struct dynvVariable* variable, ostream& out){
+static int serialize_xml(struct dynvVariable* variable, std::ostream& out)
+{
 	if (variable->ptr_value){
 		float* color = (float*)variable->ptr_value;
 		out << color[0] <<" "<< color[1] <<" "<< color[2] <<" "<< color[3];
@@ -110,28 +111,27 @@ static int serialize_xml(struct dynvVari
 	return 0;
 }
 
-static int deserialize_xml(struct dynvVariable* variable, const char *data){
-	stringstream ss(stringstream::in);
+static int deserialize_xml(struct dynvVariable* variable, const char *data)
+{
+	std::stringstream ss(std::stringstream::in);
 	ss.str(data);
 	float *c = (float*)variable->ptr_value;
 	ss >> c[0] >> c[1] >> c[2] >> c[3];
 	return 0;
 }
 
-struct dynvHandler* dynv_var_color_new(){
-	struct dynvHandler* handler=dynv_handler_create("color");
-
-	handler->create=dynv_var_color_create;
-	handler->destroy=dynv_var_color_destroy;
-	handler->set=dynv_var_color_set;
-	handler->get=dynv_var_color_get;
-	handler->serialize=dynv_var_color_serialize;
-	handler->deserialize=dynv_var_color_deserialize;
-
-	handler->serialize_xml=serialize_xml;
-	handler->deserialize_xml=deserialize_xml;
-
+struct dynvHandler* dynv_var_color_new()
+{
+	struct dynvHandler* handler = dynv_handler_create("color");
+	handler->create = dynv_var_color_create;
+	handler->destroy = dynv_var_color_destroy;
+	handler->set = dynv_var_color_set;
+	handler->get = dynv_var_color_get;
+	handler->serialize = dynv_var_color_serialize;
+	handler->deserialize = dynv_var_color_deserialize;
+	handler->serialize_xml = serialize_xml;
+	handler->deserialize_xml = deserialize_xml;
 	handler->data_size = sizeof(float*);
-
 	return handler;
 }
+
