#include "Main_Manager.h"

Main_Manager::Main_Manager(int width, int height, const std::string& title) {
	display = new Display(width, height, title);
	cur_shader = new Shader("DefaultShader");
	event_system = new Event_System();
	cur_shader->Bind();
}

Main_Manager::~Main_Manager() {
	cur_shader->Unbind();
	delete display;
	delete cur_shader;
	delete event_system;
	for (std::map<std::string, BaseObject*>::iterator i = Scene.begin(); i != Scene.end(); ++i) {
		delete (*i).second;
	}
}

void Main_Manager::Update_Objects() {
	for (std::map<std::string, BaseObject*>::iterator i = Scene.begin(); i != Scene.end(); ++i) {
		(*i).second->Update();
	}
}

void Main_Manager::Update(float r, float g, float b, float a) {
	display->Clean_Display(r, g, b, a);
	Update_Objects();
	display->Swap();
}

void Main_Manager::Game_Loop() {
	while (true) {
		event_system->Get_Events();
		if (event_system->Is_App_Closed()) {
			break;
		}
		Update(0.5f, 0.5f, 0.5f, 1.0f);
	}
}

BaseObject* Main_Manager::GetObjectByName(const std::string& name) {
	return Scene[name];
}