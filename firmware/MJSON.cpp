
#include "MJSON.h"

/**
* Constructor.
*/
MJSON::MJSON()
{

}


void MJSON::setJSON(String json) {
	this->jsonData = json;
}

char * MJSON::readValue(String key){
	char * source = (char *) jsonData.c_str();  
	char * dest = (char *) key.c_str();
	char * found = strstr( source, dest );

	char *endToken = strstr(found,",");
	char *midToken = strstr(found,":");

	char obj[200];
	int index = 0;
	int indexEnd = 0;
	int indexMid = 0;
	if (found != NULL && endToken != NULL && midToken != NULL)
	{
		index = found - source;
		indexMid = midToken - source + 1;
		indexEnd = endToken - source + 1;

		int length = (indexEnd - indexMid);

		strlcpy(obj, &source[indexMid], length);
		Serial.println(obj);

	}
	return obj;

}
