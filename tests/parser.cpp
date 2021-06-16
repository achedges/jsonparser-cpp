//
// Created by Adam Hedges on 6/16/21.
//

#include <iostream>
#include "../jsonparser.h"

using namespace jsonparser;

int testArrayParser();
int testObjectParser();

int main() {
	std::cout << "Starting JSON Parser Tests: Parser" << std::endl;

	int failcnt = 0;

	failcnt += testArrayParser();
	failcnt += testObjectParser();

	return failcnt;
}

int testArrayParser() {
	std::cout << "- Array Parser....";

	std::string jsonArray = R"([ "string value", 33, 5.2, true, false, null, { "object key": "object value" } ])";
	auto parser = new JsonParser(jsonArray);
	JsonArray* array = parser->parse()->getArrayValue();

	if (array == nullptr) {
		std::cout << "ERROR: Result is not a JsonArray" << std::endl;
		return 1;
	}

	if (array->getSize() != 7) {
		std::cout << "ERROR: Unexpected array size: " << array->getSize() << std::endl;
		return 1;
	}

	if (array->get(0)->getStringValue()->value != "string value") {
		std::cout << "ERROR: Unexpected string value";
		return 1;
	}

	if (array->get(1)->getIntegerValue()->value != 33) {
		std::cout << "ERROR: Unexpected integer value" << std::endl;
		return 1;
	}

	if (array->get(2)->getFloatValue()->value != 5.2) {
		std::cout << "ERROR: Unexpected float value" << std::endl;
		return 1;
	}

	if (!array->get(3)->getBoolValue()->value) {
		std::cout << "ERROR: Unexpected bool value" << std::endl;
		return 1;
	}

	if (array->get(4)->getBoolValue()->value) {
		std::cout << "ERROR: Unexpected bool value" << std::endl;
		return 1;
	}

	if (array->get(5)->getNullValue() == nullptr) {
		std::cout << "ERROR: Unexpected null value" << std::endl;
		return 1;
	}

	if (array->get(6)->getObjectValue() == nullptr) {
		std::cout << "ERROR: Object element not found" << std::endl;
		return 1;
	}

	if (array->get(6)->getObjectValue()->get("object key")->getStringValue()->value != "object value") {
		std::cout << "ERROR: Unxpected object key/value pair" << std::endl;
		return 1;
	}

	std::cout << "ok" << std::endl;

	return 0;
}

int testObjectParser() {
	std::cout << "- Object Parser...";

	std::string input = R"({ "string": "value", "int": 12, "float": 77.2, "true": true, "false": false, "null": null, "array": [ 1, 2 ], "object": { "nested": "value" } })";
	auto parser = new JsonParser(input);
	JsonObject* object = parser->parse()->getObjectValue();

	JsonString* jsonString = object->get("string")->getStringValue();
	JsonInteger* jsonInteger = object->get("int")->getIntegerValue();
	JsonFloat* jsonFloat = object->get("float")->getFloatValue();
	JsonBoolean* jsonTrue = object->get("true")->getBoolValue();
	JsonBoolean* jsonFalse = object->get("false")->getBoolValue();
	JsonNull* jsonNull = object->get("null")->getNullValue();
	JsonArray* jsonArray = object->get("array")->getArrayValue();
	JsonObject* jsonObject = object->get("object")->getObjectValue();

	if (jsonString == nullptr || jsonString->value != "value") {
		std::cout << "ERROR: Unexpected string value" << std::endl;
		return 1;
	}

	if (jsonInteger == nullptr || jsonInteger->value != 12) {
		std::cout << "ERROR: Unexpected integer value" << std::endl;
		return 1;
	}

	if (jsonFloat == nullptr || jsonFloat->value != 77.2) {
		std::cout << "ERROR: Unexpected float value" << std::endl;
		return 1;
	}

	if (jsonTrue == nullptr || !jsonTrue->value) {
		std::cout << "ERROR: Unexpected bool value" << std::endl;
		return 1;
	}

	if (jsonFalse == nullptr || jsonFalse->value) {
		std::cout << "ERROR: Unexpected bool value" << std::endl;
		return 1;
	}

	if (jsonNull == nullptr) {
		std::cout << "ERROR: JsonNull element not found" << std::endl;
		return 1;
	}

	if (jsonArray == nullptr || jsonArray->getSize() != 2) {
		std::cout << "ERROR: Array not found, or unexpected size" << std::endl;
		return 1;
	}

	if (jsonObject == nullptr || jsonObject->getSize() != 1) {
		std::cout << "ERROR: Object not found, or unexpected size" << std::endl;
		return 1;
	}

	JsonString* jsonNestedObject = jsonObject->get("nested")->getStringValue();

	if (jsonNestedObject == nullptr || jsonNestedObject->value != "value") {
		std::cout << "ERROR: Nested object not found, or unexpected value" << std::endl;
		return 1;
	}

	std::cout << "ok" << endl;

	return 0;
}