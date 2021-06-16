//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	JsonInteger::JsonInteger(int value) {
		this->value = value;
	}

	string JsonInteger::serialize(int indent) {
		return std::to_string(value);
	}

	JsonFloat* JsonInteger::getFloatValue() {
		return new JsonFloat((double)value);
	}

	JsonInteger* JsonInteger::getIntegerValue() {
		return this;
	}

}