//
// Created by Adam Hedges on 6/14/21.
//

#include "../JsonTypes.h"

namespace jsonparser {

	string JsonObject::serialize(int indent) {
		return "-object-";
	}

	JsonObject* JsonObject::getObjectValue() {
		return this;
	}

	size_t JsonObject::getSize() {
		return _map.size();
	}

	bool JsonObject::contains(string* key) {
		return _map.find(*key) != _map.end();
	}

	JsonTypes* JsonObject::get(string* key) {
		return _map[*key];
	}

	void JsonObject::set(string* key, JsonTypes* type) {
		_map[*key] = type;
	}

	std::set<string> JsonObject::getKeys() {
		std::set<string> keys;
		for (auto& p : _map) {
			keys.insert(p.first);
		}
		return keys;
	}

}