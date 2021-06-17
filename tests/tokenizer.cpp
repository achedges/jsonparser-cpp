//
// Created by Adam Hedges on 6/17/21.
//

#include <iostream>
#include "runtests.h"
#include "../jsonparser.h"

using namespace jsonparser;

int testTokenStream() {
	std::cout << "- Stream" << std::string(TEST_LABEL_PREFIX_LEN - 6, '.');

	std::string json = R"({ "string-key": "string-value", "int-key": 1, "float-key": 1.0, "bool-key": true, "null-key": null, "array-key": [ false ] })";
	JsonParser parser(json);
	parser.parse();

	std::vector<std::string> expectedStream { "{", "ID: string-key", ":", "ID: string-value", ",", "ID: int-key", ":", "LIT: 1", ",", "ID: float-key", ":", "LIT: 1.0", ",", "ID: bool-key", ":", "LIT: true", ",", "ID: null-key", ":", "LIT: null", ",", "ID: array-key", ":", "[", "LIT: false", "]", "}" };

	if (parser.tokenStream.size() != expectedStream.size()) {
		std::cout << "ERROR: Unexpected token stream size: " << parser.tokenStream.size() << std::endl;
		return 1;
	}

	for (int i = 0; i < expectedStream.size(); i++) {
		std::string t = parser.tokenStream[i]->toString();
		if (t != expectedStream[i]) {
			std::cout << "ERROR: Unexpected token at index " << i << ": " << t << std::endl;
			return 1;
		}
	}

	std::cout << "ok" << std::endl;

	return 0;
}