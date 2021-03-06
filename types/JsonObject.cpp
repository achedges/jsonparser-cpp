//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	string JsonObject::serialize(int indent) {
		string objectString = "{ ";
		if (indent > 0) {
			objectString += '\n';
		}

		string tab = indent > 0 ? string(indent, '\t') : "";
		size_t _size = getSize();
		for (auto & entry : map) {
			objectString += tab + "\"" + entry.first + "\": " + entry.second->serialize(indent > 0 ? indent + 1 : 0);
			if ((--_size) > 0) {
				objectString += ", ";
			}
			if (indent > 0) {
				objectString += '\n';
			}
		}

		objectString += indent > 0 ? tab.substr(0, indent - 1) : " ";
		objectString += "}";

		return objectString;
	}

	JsonObject* JsonObject::getObjectValue() {
		return this;
	}

	size_t JsonObject::getSize() {
		return map.size();
	}

	bool JsonObject::contains(string* key) {
		return map.find(*key) != map.end();
	}

	JsonTypes* JsonObject::get(string* key) {
		return map[*key];
	}

	JsonTypes* JsonObject::get(const string & key) {
		return map[key];
	}

	void JsonObject::set(string* key, JsonTypes* type) {
		map[*key] = type;
	}

	void JsonObject::set(const string & key, JsonTypes* type) {
		map[key] = type;
	}

	std::set<string> JsonObject::getKeys() {
		std::set<string> keys;
		for (auto& p : map) {
			keys.insert(p.first);
		}
		return keys;
	}

}