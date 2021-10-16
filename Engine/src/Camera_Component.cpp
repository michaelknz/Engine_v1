#include "Camera_Component.h"

Camera_Component::Camera_Component() {

}

Camera_Component::~Camera_Component() {

}

void Camera_Component::Init_Dependencies(std::map<std::string, Base_Component*> comps) {
	transform = static_cast<Transform_Component*>(comps["transform"]);
}

glm::mat4 Camera_Component::Get_View() {
	glm::vec3 camera_pos = transform->Get_Position();
	glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
	camera_up = glm::rotate(glm::mat4(1.0f), glm::radians(transform->Get_Rotation().x), glm::vec3(1.0f, 0.0f, 0.0f)) * glm::vec4(camera_up, 1.0f);
	camera_up = glm::rotate(glm::mat4(1.0f), glm::radians(transform->Get_Rotation().z), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::vec4(camera_up, 1.0f);
	camera_front = glm::rotate(glm::mat4(1.0f), glm::radians(transform->Get_Rotation().x), glm::vec3(1.0f, 0.0f, 0.0f)) * glm::vec4(camera_front, 1.0f);
	camera_front = glm::rotate(glm::mat4(1.0f), glm::radians(transform->Get_Rotation().y), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(camera_front, 1.0f);
	glm::mat4 view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
	return view;
}

glm::mat4 Camera_Component::Get_Perspective() {
	glm::mat4 projection = glm::perspective(glm::radians(fov), aspect, zNear, zFar);
	return projection;
}

void Camera_Component::Init(Base_Info* info) {
	Camera_Component_Info* inf = static_cast<Camera_Component_Info*>(info);
	fov = inf->fov;
	zNear = inf->zNear;
	zFar = inf->zFar;
	aspect = inf->aspect;
}

void Camera_Component::Execute() {
	Connect_Manager* con = Connect_Manager::get_Instace();
	con->Send_View(Get_View());
	con->Send_Projection(Get_Perspective());
}