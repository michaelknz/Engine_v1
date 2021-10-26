#include "Event_System.h"

Event_System::Event_System():is_events(false) {

}

Event_System::~Event_System() {

}

void Event_System::Get_Events() {
	is_events = SDL_PollEvent(&Event);
}

bool Event_System::Is_App_Closed() {
	if (is_events) {
		if (Event.type == SDL_QUIT) {
			return true;
		}
	}
	return false;
}