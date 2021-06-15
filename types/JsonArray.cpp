//
// Created by Adam Hedges on 6/14/21.
//

#include "../JsonTypes.h"

namespace jsonparser {

	string JsonArray::serialize(int indent) {
		string arrayString = "[ ";
		if (indent > 0) {
			arrayString += '\n';
		}

		string tab = indent > 0 ? string(indent, '\t') : "";
		size_t _size = getSize();
		for (JsonTypes* t : _array) {
			arrayString += tab + t->serialize(indent);
			if ((--_size) > 0) {
				arrayString += ", ";
			}
			if (indent > 0) {
				arrayString += '\n';
			}
		}

		arrayString += indent > 0 ? tab.substr(0, indent - 1) : " ";
		arrayString += ']';

		return arrayString;
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