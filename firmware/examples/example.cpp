#include "MJSON.h"

MJSON *parser;

void setup() {
  Serial.begin(9600);

  parser = new MJSON();
    
}

void loop() {
	
	// String js = "{\"list\":[{\"dt\":\"1423242000\",\"temp\":{\"day\":-9.1,\"min\":-11.19,\"max\":-9.1,\"night\":-11.19,\"eve\":-9.1,\"morn\":-9.1},\"pressure\":1018.1,\"humidity\":64,\"weather\":[{\"id\":803,\"main\":\"Clouds\",\"description\":\"broken clouds\",\"icon\":\"04n\"}],\"speed\":2.86,\"deg\":291,\"clouds\":68}]}";


	String js = "{\"success\":{\"total\":1},\"contents\":{\"id\":\"R39s9zZseG91FAmCsdpKeAeF\",\"quote\":\"Winning isn't everything, but the will to win is everything.\",\"author\":\"Vince Lombardi\",\"length\":\"60\",\"tags\":[\"inspire\",\"olympic\",\"sports\",\"winning\",\"winning-and-losing\"],\"category\":\"inspire\"}}";

    parser->setJSON(js);  
    
	float temp_low = atof(parser->readValue("total"));
	float temp_high = atof(parser->readValue("length"));
	String city = parser->readValue("quote");
	String descr = parser->readValue("author");



}