#include <iostream>
#include "JsonTypes.h"

using namespace jsonparser;

int main() {
	std::cout << "Hello, World!" << std::endl;

	auto j = new JsonString("test string");
	std::cout << j->serialize(0) << std::endl;

	return 0;
}
