//
// Created by Adam Hedges on 6/17/21.
//

#include <iostream>
#include "runtests.h"

int main() {
	int failcnt = 0;

	std::cout << "Running tokenizer tests" << std::endl;
	failcnt += testTokenStream();

	std::cout << "Running parser tests" << std::endl;
	failcnt += testArrayParser();
	failcnt += testObjectParser();

	std::cout << "Running serializer tests" << std::endl;
	failcnt += testJsonArray();
	failcnt += testJsonBoolean();
	failcnt += testJsonFloat();
	failcnt += testJsonInteger();
	failcnt += testJsonNull();
	failcnt += testJsonObject();
	failcnt += testJsonString();

	return failcnt;
}