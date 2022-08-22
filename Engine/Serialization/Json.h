#pragma once
#include "rapidjson/document.h"
#include <string>

#define READ_DATA(value, data) nae::json::Get(value, #data, data)




namespace nae
{
	struct Vector2;
	struct Color;
	struct Rect;

	namespace json
{
	bool Load(const std::string& filename, rapidjson::Document& document);

	bool Get(const rapidjson::Value& value, const std::string& name, int& data);
	bool Get(const rapidjson::Value& value, const std::string& name, float& data);
	bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
	bool Get(const rapidjson::Value& value, const std::string& name, std::string& data);
	bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data);
	bool Get(const rapidjson::Value& value, const std::string& name, Color& data);
	bool Get(const rapidjson::Value& value, const std::string& name, Rect& data);

}
}