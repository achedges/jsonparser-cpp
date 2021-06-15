//
// Created by Adam Hedges on 6/14/21.
//

#include "../JsonTypes.h"

namespace jsonparser {

	JsonInteger::JsonInteger(int value) {
		_value = value;
	}

	string JsonInteger::serialize(int indent) {
		return std::to_string(_value);
	}

	JsonFloat* JsonInteger::getFloatValue() {
		return new JsonFloat((double)_value);
	}

	JsonInteger* JsonInteger::getIntegerValue() {
		return this;
	}

}