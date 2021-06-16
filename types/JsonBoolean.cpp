//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	JsonBoolean::JsonBoolean(bool value) {
		this->value = value;
	}

	string JsonBoolean::serialize(int indent) {
		return value ? "true" : "false";
	}

	JsonBoolean* JsonBoolean::getBoolValue() {
		return this;
	}

}