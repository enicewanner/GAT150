#pragma once
#include <string>
#include <variant>
#include <functional>

namespace nae
{
	class GameObject;

	class Event
	{
	public:
		using functionPtr = std::function<void(const Event&)>;
	public:
		std::string name;
		GameObject* receiever = nullptr;
		std::variant<int, bool, float, std::string> data;

	};
}