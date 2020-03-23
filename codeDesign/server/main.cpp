//#include <jwt-cpp/jwt.h>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;


int main() {

	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	Document d;
	d.Parse(json);

	// 2. Modify it by DOM.
	Value& s = d["stars"];
	s.SetInt(s.GetInt() + 1);

	// 3. Stringify the DOM
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

	// Output {"project":"rapidjson","stars":11}
	std::cout << buffer.GetString() << std::endl;

	while (1) {};
	//if (verifie) {
	//	std::cout << "success" << "\n";
	//}
	//else {
	//	std::cout << "failed" << "\n";
	//}
	/*auto Header = cppcodec::base64_url::encode(strHeader.c_str());
	auto Payload = cppcodec::base64_url::encode(strPayload.c_str());*/
	
	return 0;
}