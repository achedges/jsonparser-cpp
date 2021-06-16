//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	string JsonNull::serialize(int indent) {
		return "null";
	}

	JsonNull* JsonNull::getNullValue() {
		return this;
	}

}