#pragma once
#include "Event.h"
#include <map>
#include <list>


namespace nae
{
	class EventManager
	{
	public:
		struct Observer
		{
			GameObject* receiver;
			Event::functionPtr function;
		};

	public:
		void Initialize();
		void Shutdown();
		void Update();

		void Subscribe(std::string& name, Event::functionPtr function, GameObject* receiever = nullptr);
		void Unsubscribe(std::string& name, GameObject* receiver);

		void Notify(const Event& _event);

	private:
		std::map<std::string, std::list<Observer>> m_events;
	};
}
