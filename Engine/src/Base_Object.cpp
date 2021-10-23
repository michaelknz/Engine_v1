#include "Base_Object.h"

BaseObject::BaseObject(Transform_Component_Info* inf) {
	Add_Component<Transform_Component>("transform", inf);
}

BaseObject::~BaseObject() {
	for (std::map<std::string, Base_Component*>::iterator i = components.begin(); i != components.end(); ++i) {
		delete (*i).second;
	}
}

void BaseObject::Init_Component_By_Name(const std::string& name, Base_Info* init_info) {
	components[name]->Init(init_info);
	components[name]->Init_Dependencies(components);
}

void BaseObject::Update_Components() {
	for (int i = 0; i < components_names.size(); ++i) {
		components[components_names[i]]->Execute();
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