#pragma once

namespace Et
{
	enum EventType
	{
		WindowsEvent,
		MouseMotionEvent,
		MouseWheelEvent,
		MouseButtonEvent,
		KeyboardEvent
	};
}

class Event
{
public:
	Event();
	virtual ~Event() = default;

	Et::EventType getEventType() const;
protected:
	Et::EventType m_type;
};

class EventHandler
{
public:
	EventHandler() = default;
	~EventHandler() {kill();}

	static void addEvent(std::unique_ptr<Event> ptr);

	static std::unique_ptr<Event> nextEvent(); //note that using that will delete the event in the dispatcher. 
	//it will no longer be stockted 

	static void kill();

	static void removeOld(); 
	//called each tick, remove the oldest Event if there are more than a hundred of them
	//i consider that the prog should have get what he wanted before going there

private:
	static std::deque<std::unique_ptr<Event>> m_listEvents;
	static bool m_isValid;
};
