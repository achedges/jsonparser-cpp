//
// Created by Adam Hedges on 6/14/21.
//

#include "../JsonTypes.h"

namespace jsonparser {

	JsonString::JsonString(string* value) {
		_value = *value;
	}

	JsonString::JsonString(const string & value) {
		_value = value;
	}

	string JsonString::serialize(int indent) {
		return _value;
	}

	JsonString* JsonString::getStringValue() {
		return this;
	}

}