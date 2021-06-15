#include <iostream>
#include "JsonTypes.h"

using namespace jsonparser;

int main() {
	std::cout << "Hello, JSON Parser!" << std::endl;

	string teststr1 = "test string 1";
	string teststr2 = "test string 2";

	auto str1 = new JsonString(&teststr1);
	auto str2 = new JsonString(&teststr2);

	auto array = new JsonArray();
	array->add(str1);
	array->add(str2);

	std::cout << array->getSize() << std::endl;
	std::cout << array->get(0)->serialize(0) << std::endl;
	std::cout << array->get(1)->serialize(0) << std::endl;

	string key1 = "key1";
	string key2 = "key2";

	auto obj = new JsonObject();
	obj->set(&key1, str1);
	obj->set(&key2, str2);

	std::cout << obj->getSize() << std::endl;
	std::cout << obj->get(&key1)->serialize(0) << std::endl;
	std::cout << obj->get(&key2)->serialize(0) << std::endl;

	string badkey = "bogus";
	std::cout << "Contains 'bogus'? " << obj->contains(&badkey) << std::endl;
	std::cout << "Contains 'key1'? " << obj->contains(&key1) << std::endl;
	std::cout << "Keys:" << std::endl;
	for (auto& k : obj->getKeys()) {
		cout << "  " << k << std::endl;
	}

	// test serializers
	auto jsonArray = new JsonArray();
	auto jsonBool = new JsonBoolean(true);
	auto jsonFloat = new JsonFloat(12.34);
	auto jsonInt = new JsonInteger(1234);
	auto jsonNull = new JsonNull();
	auto jsonObj = new JsonObject();
	auto jsonStr = new JsonString("test serializer");

	std::cout << jsonArray->serialize(0) << std::endl;
	std::cout << jsonBool->serialize(0) << std::endl;
	std::cout << jsonFloat->serialize(0) << std::endl;
	std::cout << jsonInt->serialize(0) << std::endl;
	std::cout << jsonNull->serialize(0) << std::endl;
	std::cout << jsonObj->serialize(0) << std::endl;
	std::cout << jsonStr->serialize(0) << std::endl;

	return 0;
}
