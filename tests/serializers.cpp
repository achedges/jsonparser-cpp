//
// Created by Adam Hedges on 6/15/21.
//

#include <iostream>
#include "../types/JsonTypes.h"

int testJsonArray();
int testJsonBoolean();
int testJsonFloat();
int testJsonInteger();
int testJsonNull();
int testJsonObject();
int testJsonString();

using namespace jsonparser;

int main() {
	std::cout << "Starting JSON Parser Tests: Serializers" << std::endl;

	int failcnt = 0;

	failcnt += testJsonArray();
	failcnt += testJsonBoolean();
	failcnt += testJsonFloat();
	failcnt += testJsonInteger();
	failcnt += testJsonNull();
	failcnt += testJsonObject();
	failcnt += testJsonString();

	return failcnt;
}

int testJsonArray() {
	std::cout << "- JsonArray.....";

	auto a = new JsonArray();
	a->add(new JsonString("test string one"));
	a->add(new JsonInteger(12));

	std::string expected = R"([ "test string one", 12 ])";
	std::string array = a->serialize(0);

	if (array == expected) {
		std::cout << "ok" << std::endl;
		return 0;
	} else {
		std::cout << "ERROR: Unexpected value '" << array << "'" << std::endl;
		return 1;
	}
}

int testJsonBoolean() {
	std::cout << "- JsonBoolean...";

	auto t = new JsonBoolean(true);
	auto f = new JsonBoolean(false);

	std::string t_result = t->serialize(0);
	std::string f_result = f->serialize(0);

	if (t_result != "true") {
		std::cout << "ERROR: Unexpected value '" << t_result << "'" << std::endl;
		return 1;
	} else if (f_result != "false") {
		std::cout << "ERROR: Unexpected value '" << f_result << "'" << std::endl;
		return 1;
	} else {
		std::cout << "ok" << std::endl;
		return 0;
	}
}

int testJsonFloat() {
	std::cout << "- JsonFloat.....";

	auto f = new JsonFloat(9.876);
	std::string result = f->serialize(0);

	if (result == "9.876000") {
		std::cout << "ok" << std::endl;
		return 0;
	} else {
		std::cout << "ERROR: Unexpected value '" << result << "'" << std::endl;
		return 1;
	}
}

int testJsonInteger() {
	std::cout << "- JsonInteger...";

	auto i = new JsonInteger(312);
	std::string result = i->serialize(0);

	if (result == "312") {
		std::cout << "ok" << std::endl;
		return 0;
	} else {
		std::cout << "ERROR: Unexpected value '" << result << "'" << std::endl;
		return 1;
	}
}

int testJsonNull() {
	std::cout << "- JsonNull......";

	auto n = new JsonNull();
	std::string result = n->serialize(0);

	if (result == "null") {
		std::cout << "ok" << std::endl;
		return 0;
	} else {
		std::cout << "ERROR: Unexpected value '" << result << "'" << std::endl;
		return 1;
	}
}

int testJsonObject() {
	std::cout << "- JsonObject....";

	auto o = new JsonObject();
	o->set("int-value", new JsonInteger(123));
	o->set("string-value", new JsonString("some value"));
	o->set("nested-object", new JsonObject());
	o->get("nested-object")->getObjectValue()->set("nested-value", new JsonString("some nested value"));

	std::string result = o->serialize(0);
	std::string expected = R"({ "int-value": 123, "nested-object": { "nested-value": "some nested value" }, "string-value": "some value" })";

	if (result == expected) {
		std::cout << "ok" << std::endl;
		return 0;
	} else {
		std::cout << "ERROR: Unexpected value '" << result << "'" << std::endl;
		return 1;
	}
}

int testJsonString() {
	std::cout << "- JsonString....";

	auto s = new JsonString("some longer string value");
	std::string result = s->serialize(0);

	if (result == R"("some longer string value")") {
		std::cout << "ok" << std::endl;
		return 0;
	} else {
		std::cout << "ERROR: Unexpected value '" << result << "'" << std::endl;
		return 1;
	}
}
