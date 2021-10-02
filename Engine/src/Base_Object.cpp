#include "Base_Object.h"

BaseObject::BaseObject() {

}

BaseObject::~BaseObject() {
	for (std::map<std::string, Base_Component*>::iterator i = components.begin(); i != components.end(); ++i) {
		delete (*i).second;
	}
}

void BaseObject::Init_Component_By_Name(const std::string& name, Base_Info* init_info) {
	components[name]->Init(init_info);
}

void BaseObject::Update_Components() {
	for (std::map<std::string, Base_Component*>::iterator i = components.begin(); i != components.end(); ++i) {
		(*i).second->Execute();
	}
}

void BaseObject::Init_Entity() {

}

void BaseObject::Update_Entity() {

}

void BaseObject::Update() {
	Update_Entity();
	Update_Components();
}