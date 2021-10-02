#ifndef MAIN_MANAGER_H
#define MAIN_MANAGER_H

#include <map>
#include <string>
#include "Base_Object.h"
#include "Shader.h"
#include "Display.h"

class Main_Manager {
public:
	Main_Manager(int width, int height, const std::string& title);
	~Main_Manager();
	template<typename T>
	void Add_Object(const std::string& name) {
		Scene[name] = new T;
	}
	BaseObject* GetObjectByName(const std::string& name);
	void Update_Objects();
	void Update();
private:
	std::map<std::string, BaseObject*> Scene;
	Shader* cur_shader;
	Display* display;
};

#endif