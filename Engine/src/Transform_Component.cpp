#include "Transform_Component.h"

Transform_Component::Transform_Component() {

}

Transform_Component::~Transform_Component() {

}

glm::mat4 Transform_Component::Get_Model() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, scale);

	model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	model = glm::translate(model, position);

	return model;
}

void Transform_Component::Init(Base_Info* info) {
	Transform_Component_Info* inf = static_cast<Transform_Component_Info*>(info);
	position = inf->position;
	rotation = inf->rotation;
	scale = inf->scale;
}

void Transform_Component::Execute() {
	Connect_Manager* cinst = Connect_Manager::get_Instace();

}