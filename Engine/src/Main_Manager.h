#ifndef MAIN_MANAGER_H
#define MAIN_MANAGER_H

#include <map>
#include <string>
#include <vector>
#include "Base_Object.h"
#include "Shader.h"
#include "Display.h"
#include "Event_System.h"
#include "Connect_Manager.h"
#include "Camera.h"

class Main_Manager {
public:
	Main_Manager(int width, int height, const std::string& title);
	~Main_Manager();
	template<typename T>
	void Add_Object(const std::string& name, Transform_Component_Info* tinf) {
		Scene[name] = new T(tinf);
		objects_names.push_back(name);
	}
	BaseObject* GetObjectByName(const std::string& name);
	void Game_Loop();
private:
	void Update_Objects();
	void Init_Scene();
	void Add_Camera();
	void Update(float r, float g, float b, float a);
	std::map<std::string, BaseObject*> Scene;
	std::vector<std::string> objects_names;
	Shader* cur_shader;
	Display* display;
	Event_System* event_system;
	int width;
	int height;
};

#endif