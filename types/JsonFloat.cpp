//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	JsonFloat::JsonFloat(double value) {
		this->value = value;
	}

	string JsonFloat::serialize(int indent) {
		return std::to_string(value);
	}

	JsonFloat* JsonFloat::getFloatValue() {
		return this;
	}

	JsonInteger* JsonFloat::getIntegerValue() {
		return new JsonInteger((int)value);
	}

}