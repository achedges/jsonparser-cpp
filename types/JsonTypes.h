//
// Created by Adam Hedges on 6/12/21.
//

#ifndef JSONPARSER_JSONTYPES_H
#define JSONPARSER_JSONTYPES_H

#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace jsonparser {

	// forward declarations
	class JsonArray;
	class JsonBoolean;
	class JsonFloat;
	class JsonInteger;
	class JsonNull;
	class JsonObject;
	class JsonString;

	class JsonTypes {
	public:
		virtual string serialize(int indent) = 0;

		virtual JsonArray* getArrayValue() { return nullptr; }
		virtual JsonBoolean* getBoolValue() { return nullptr; }
		virtual JsonFloat* getFloatValue() { return nullptr; }
		virtual JsonInteger* getIntegerValue() { return nullptr; }
		virtual JsonNull* getNullValue() { return nullptr; }
		virtual JsonObject* getObjectValue() { return nullptr; }
		virtual JsonString* getStringValue() { return nullptr; }
	};

	class JsonArray : public JsonTypes {
	private:
		vector<JsonTypes*> _array;
	public:
		string serialize(int indent) override;
		JsonArray* getArrayValue() override;
		size_t getSize();
		JsonTypes* get(int index);
		void add(JsonTypes* jsonType);
	};

	class JsonBoolean : public JsonTypes {
	private:
		bool _value;
	public:
		explicit JsonBoolean(bool value);
		string serialize(int indent) override;
		JsonBoolean* getBoolValue() override;
	};

	class JsonFloat : public JsonTypes {
	private:
		double _value;
	public:
		explicit JsonFloat(double value);
		string serialize(int indent) override;
		JsonFloat* getFloatValue() override;
		JsonInteger* getIntegerValue() override;
	};

	class JsonInteger : public JsonTypes {
	private:
		int _value;
	public:
		explicit JsonInteger(int value);
		string serialize(int indent) override;
		JsonFloat* getFloatValue() override;
		JsonInteger* getIntegerValue() override;
	};

	class JsonNull : public JsonTypes {
	public:
		string serialize(int indent) override;
		JsonNull* getNullValue() override;
	};

	class JsonObject : public JsonTypes {
	private:
		std::map<string, JsonTypes*> _map;
	public:
		string serialize(int indent) override;
		JsonObject* getObjectValue() override;
		size_t getSize();
		bool contains(string* key);
		JsonTypes* get(string* key);
		JsonTypes* get(const string & key);
		void set(string* key, JsonTypes* type);
		void set(const string & key, JsonTypes* type);
		std::set<string> getKeys();
	};

	class JsonString : public JsonTypes {
	private:
		string _value;
	public:
		explicit JsonString(string* value);
		explicit JsonString(const string & value);
		string serialize(int indent) override;
		JsonString* getStringValue() override;

	};

}

#endif //JSONPARSER_JSONTYPES_H
