//
// Created by Adam Hedges on 6/15/21.
//

#ifndef JSONPARSER_JSONPARSER_H
#define JSONPARSER_JSONPARSER_H

#include <iostream>
#include <vector>
#include "types/JsonTypes.h"

namespace jsonparser {

	class JsonToken {
	public:
		std::string token;
		std::string text;
		JsonToken(const char & token, const char & text);
		JsonToken(const std::string & token, const std::string & text);
		[[nodiscard]] std::string toString() const;
	};

	class JsonParser {
	private:
		std::string input;
		size_t n = 0;
		size_t i = 0;

		void tokenize();
		JsonToken* nextToken();
		static JsonTypes* parseLiteral(const std::string & text);
		JsonTypes* parseArray();
		JsonTypes* parseObject();
	public:
		std::vector<JsonToken*> tokenStream;

		explicit JsonParser(const std::string & jsonString);
		JsonTypes* parse();
	};

}

#endif //JSONPARSER_JSONPARSER_H
