#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include <map>
#include <glew.h>
#include <vector>
#include "Core/Base_Component.h"
#include "Core/Transform_Component.h"

class BaseObject {
public:
	BaseObject();
	~BaseObject();
	template <typename T>
	void Add_Component(int component_name, Base_Info* init_info) {
		components[component_name] = new T;
		Init_Component_By_Name(component_name, init_info);
	}

	virtual void Init_Entity();
	virtual void Update_Entity();
	void Update();
	void Init(Transform_Component_Info* inf);
	Base_Component* GetComponentByName(int name);
private:
	void Init_Object(Transform_Component_Info* inf);
	void Init_Component_By_Name(int name, Base_Info* init_info);
	std::map<int,Base_Component*> components;
};

#endif
