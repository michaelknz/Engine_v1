#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include <map>
#include <string>
#include "Base_Component.h"

class BaseObject {
public:
	BaseObject();
	~BaseObject();
	template <typename T>
	void Add_Component(const std::string& component_name, Base_Info* init_info) {
		components[component_name] = new T;
		Init_Component_By_Name(component_name, init_info);
	}
	void Init_Component_By_Name(const std::string& name, Base_Info* init_info);
	void Update_Components();
	virtual void Init_Entity();
	virtual void Update_Entity();
	void Update();
private:
	std::map<std::string,Base_Component*> components;
};

#endif
