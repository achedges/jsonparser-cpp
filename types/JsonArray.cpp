//
// Created by Adam Hedges on 6/14/21.
//

#include "../JsonTypes.h"

namespace jsonparser {

	string JsonArray::serialize(int indent) {
		return "-array-";
	}

	JsonArray* JsonArray::getArrayValue() {
		return this;
	}

	size_t JsonArray::getSize() {
		return _array.size();
	}

	JsonTypes* JsonArray::get(int index) {
		return _array[index];
	}

	void JsonArray::add(JsonTypes* jsonType) {
		_array.push_back(jsonType);
	}

}