//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	JsonBoolean::JsonBoolean(bool value) {
		_value = value;
	}

	string JsonBoolean::serialize(int indent) {
		return _value ? "true" : "false";
	}

	JsonBoolean* JsonBoolean::getBoolValue() {
		return this;
	}

}