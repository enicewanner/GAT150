#include "EventManager.h"

namespace nae
{

	void EventManager::Initialize()
	{
	}

	void EventManager::Shutdown()
	{
	}

	void EventManager::Update()
	{
	}

	void EventManager::Subscribe(std::string& name, Event::functionPtr function, GameObject* receiever)
	{
		Observer observer;
		observer.receiver = receiever;
		observer.function = function;

		m_events[name].push_back(observer);
	}

	void EventManager::Unsubscribe(std::string& name, GameObject* receiver)
	{
	}

	void EventManager::Notify(const Event& _event)
	{
		auto& observers = m_events[_event.name];
		for (auto& observer : observers)
		{
			if (_event.receiever == nullptr || _event.receiever == observer.receiver)
			{
				observer.function(_event);
			}
		}

	}
}
