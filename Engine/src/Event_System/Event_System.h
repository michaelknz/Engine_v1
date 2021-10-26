#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include <SDL.h>

class Event_System {
public:
	Event_System();
	~Event_System();
	void Get_Events();
	bool Is_App_Closed();
private:
	SDL_Event Event;
	bool is_events;
};

#endif