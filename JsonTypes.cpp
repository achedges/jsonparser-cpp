//
// Created by Adam Hedges on 6/14/21.
//

#include "JsonTypes.h"

namespace jsonparser {

	// JsonArray impl
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
	};

	void JsonArray::add(JsonTypes* jsonType) {
		_array.push_back(jsonType);
	}

	// JsonBoolean impl
	JsonBoolean::JsonBoolean(bool value) {
		_value = value;
	}

	string JsonBoolean::serialize(int indent) {
		return _value ? "true" : "false";
	}

	JsonBoolean* JsonBoolean::getBoolValue() {
		return this;
	}

	// JsonFloat impl
	JsonFloat::JsonFloat(double value) {
		_value = value;
	}

	string JsonFloat::serialize(int indent) {
		return "-float-";
	}

	JsonFloat* JsonFloat::getFloatValue() {
		return this;
	}

	JsonInteger* JsonFloat::getIntegerValue() {
		return new JsonInteger((int)_value);
	}

	// JsonInteger impl
	JsonInteger::JsonInteger(int value) {
		_value = value;
	}

	string JsonInteger::serialize(int indent) {
		return "-integer-";
	}

	JsonFloat* JsonInteger::getFloatValue() {
		return new JsonFloat((double)_value);
	}

	JsonInteger* JsonInteger::getIntegerValue() {
		return this;
	}

	// JsonNull impl
	string JsonNull::serialize(int indent) {
		return "null";
	}

	JsonNull* JsonNull::getNullValue() {
		return this;
	}

	// JsonObject impl
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
		return false;
	}

	JsonTypes* JsonObject::get(string* key) {
		return nullptr;
	}

	void JsonObject::set(string* key, JsonTypes* type) {

	}

	std::set<string> JsonObject::getKeys() {
		return std::set<string>();
	}

	// JsonString impl
	JsonString::JsonString(string value) {
		_value = value;
	}

	string JsonString::serialize(int indent) {
		return _value;
	}

	JsonString* JsonString::getStringValue() {
		return this;
	}

}