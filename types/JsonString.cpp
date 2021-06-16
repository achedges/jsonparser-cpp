//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	JsonString::JsonString(string* value) {
		this->value = *value;
	}

	JsonString::JsonString(const string & value) {
		this->value = value;
	}

	string JsonString::serialize(int indent) {
		return '"' + value + '"';
	}

	JsonString* JsonString::getStringValue() {
		return this;
	}

}