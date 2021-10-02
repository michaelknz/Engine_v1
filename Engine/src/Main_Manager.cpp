#include "Main_Manager.h"

Main_Manager::Main_Manager(int width, int height, const std::string& title) {
	display = new Display(width, height, title);
	cur_shader = new Shader("DefaultShader");
	cur_shader->Bind();
}

Main_Manager::~Main_Manager() {
	cur_shader->Unbind();
	delete display;
	for (std::map<std::string, BaseObject*>::iterator i = Scene.begin(); i != Scene.end(); ++i) {
		delete (*i).second;
	}
}

void Main_Manager::Update_Objects() {
	for (std::map<std::string, BaseObject*>::iterator i = Scene.begin(); i != Scene.end(); ++i) {
		(*i).second->Update();
	}
}

void Main_Manager::Update() {
	display->Clean_Display(0.5f, 0.5f, 0.5f, 1.0f);
	Update_Objects();
	display->Swap();
}

BaseObject* Main_Manager::GetObjectByName(const std::string& name) {
	return Scene[name];
}