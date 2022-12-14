#include "EventManager.h"

namespace crae
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

	void EventManager::Subscribe(const std::string& name, Event::functionPtr function, GameObject* receiver)
	{
		Observer observer;
		observer.receiver = receiver;
		observer.function = function;

		m_events[name].push_back(observer);
	}

	void EventManager::Unsubscribe(const std::string& name, GameObject* receiver)
	{
	}

	void EventManager::Notify(const Event& event)
	{
		auto& observers = m_events[event.name];

		for (auto& observer : observers)
		{
			if (!event.reciever || event.reciever == observer.receiver)
			{
				observer.function(event);
			}
		}
	}

}

