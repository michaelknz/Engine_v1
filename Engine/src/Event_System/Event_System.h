#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include <SDL.h>

class Event_System {
public:
	static Event_System* getInstance();
	static void deleteInstance();
	Event_System();
	~Event_System();
	void Get_Events();
	bool Is_App_Closed();
private:
	static Event_System* instance;
	SDL_Event Event;
	bool is_events;
};

#endif