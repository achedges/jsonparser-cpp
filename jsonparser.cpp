//
// Created by Adam Hedges on 6/15/21.
//

#include <set>
#include "jsonparser.h"

namespace jsonparser {

	// JsonToken impl
	JsonToken::JsonToken(const char & token, const char & text) {
		this->token = token;
		this->text = text;
	}
	JsonToken::JsonToken(const std::string & token, const std::string & text) {
		this->token = token;
		this->text = text;
	}

	std::string JsonToken::toString() const {
		return (token == text) ? token : token + ": " + text;
	}

	// JsonParser impl
	JsonParser::JsonParser(const std::string & jsonString) {
		input = jsonString;
		n = input.length();
		i = 0;
	}

	JsonTypes* JsonParser::parse() {
		tokenize();
		i = 0;

		if (tokenStream[0]->token == "{") {
			return parseObject();
		} else if (tokenStream[0]->token == "[") {
			return parseArray();
		} else {
			std::cout << "JSON documents must start with '{' or '['" << std::endl;
			return nullptr;
		}
	}

	// private implementations
	void JsonParser::tokenize() {
		std::set<char> discards {' ', '\t', '\n', '\r' };
		std::set<char> tokens { '{', '}', '[', ']', ',', ':' };

		i = 0;
		while (i < n) {
			// discard?
			if (discards.find(input[i]) != discards.end()) {
				i++;
				continue;
			}
			// punctuation/token literal?
			else if (tokens.find(input[i]) != tokens.end()) {
				tokenStream.push_back(new JsonToken(input[i], input[i]));
			}
			// identifier?
			else if (input[i] == '"') {
				std::string id;
				i++;
				while (i < n) {
					if (input[i] == '"' && input[i - 1] != '\\') {
						break;
					} else if (input[i] == '"' && input[i - 1] == '\\') {
						id[id.length() - 1] = '"';
					} else {
						id += input[i];
					}

					i++;
				}

				tokenStream.push_back(new JsonToken("ID", id));
			}
			// must be a literal...
			else {
				std::string lit;
				while (i < n) {
					if (input[i] == ',' || input[i] == ']' || input[i] == '}') {
						i--; // back up so we can capture the ending token in the stream
						break;
					} else if (discards.find(input[i]) == discards.end()) {
						lit += input[i];
					}

					i++;
				}

				tokenStream.push_back(new JsonToken("LIT", lit));
			}

			i++;
		}
	}

	JsonToken* JsonParser::nextToken() {
		i++;
		if (i < tokenStream.size()) {
			return tokenStream[i];
		} else {
			return new JsonToken("EOF", "EOF");
		}
	}

	JsonTypes* JsonParser::parseLiteral(const std::string & text) {
		if (text == "true")
			return new JsonBoolean(true);
		else if (text == "false")
			return new JsonBoolean(false);
		else if (text == "null")
			return new JsonNull();
		else if (text.find_first_of('.', 0) >= 0)
			return new JsonFloat(std::stod(text));
		else
			return new JsonInteger(std::stoi(text));
	}

	JsonTypes* JsonParser::parseArray() {
		auto array = new JsonArray();
		JsonToken* token = this->nextToken();

		while (token->token != "]") {
			if (token->token == "ID") {
				array->add(new JsonString(token->text));
			} else if (token->token == "LIT") {
				array->add(this->parseLiteral(token->text));
			} else if (token->token == "{") {
				array->add(this->parseObject());
			} else if (token->token == "[") {
				array->add(this->parseArray());
			}

			token = this->nextToken();
			if (token->token == "EOF")
				break;
		}

		return array;
	}

	JsonTypes* JsonParser::parseObject() {
		auto object = new JsonObject();
		JsonToken* key = this->nextToken();

		while (key->token != "}") {
			if (key->token == ",") {
				key = this->nextToken();
			}

			JsonToken* separator = this->nextToken();
			JsonToken* value = this->nextToken();

			if (key->token != "ID") {
				std::cout << "Invalid token detected for object key: " << key->token << std::endl;
				return object;
			}

			if (separator->token != ":") {
				std::cout << "Invalid token detected for key-value separator: " << separator->token << std::endl;
				return object;
			}

			if (value->token == "{") {
				object->set(key->text, this->parseObject());
			} else if (value->token == "[") {
				object->set(key->text, this->parseArray());
			} else if (value->token == "ID") {
				object->set(key->text, new JsonString(value->text));
			} else if (value->token == "LIT") {
				object->set(key->text, this->parseLiteral(value->text));
			} else {
				std::cout << "Unknown value token: " << value->token << std::endl;
				return object;
			}

			key = this->nextToken();
		}

		return object;
	}

}