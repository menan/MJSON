#include "MJSON.h"

MJSON *parser;

void setup() {
  Serial.begin(9600);

  parser = new MJSON();
    
}

void loop() {
	
	String js = "{\"list\":[{\"dt\":\"1423242000\",\"temp\":{\"day\":-9.1,\"min\":-11.19,\"max\":-9.1,\"night\":-11.19,\"eve\":-9.1,\"morn\":-9.1},\"pressure\":1018.1,\"humidity\":64,\"weather\":[{\"id\":803,\"main\":\"Clouds\",\"description\":\"broken clouds\",\"icon\":\"04n\"}],\"speed\":2.86,\"deg\":291,\"clouds\":68}]}";

    parser->setJSON(js);  
    
	float temp_low = atof(parser->readValue("min"));
	float temp_high = atof(parser->readValue("max"));
	String city = parser->readValue("name");
	String descr = parser->readValue("description");



}