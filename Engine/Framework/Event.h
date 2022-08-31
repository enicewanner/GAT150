#pragma once
#include <string>
#include <variant>
#include <functional>

namespace nae {

	class GameObject;
	class Event {
	public:
		using functionPtr = std::function<void(const Event&)>;

		std::string name;
		GameObject* receiver = nullptr;
		std::variant<int, bool, float, std::string> data;

	};

	class INotify {
	public:
		virtual void OnNotify(const Event& event) = 0;
	};
}