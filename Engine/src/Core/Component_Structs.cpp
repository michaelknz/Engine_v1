#include "Component_Structs.h"

Mesh_Component_Info::Mesh_Component_Info(std::string init) {
	filename = init;
}

Color::Color(float r, float g, float b, float a) {
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

Transform_Component_Info::Transform_Component_Info(glm::vec3 p, glm::vec3 r, glm::vec3 s) {
	position = p;
	rotation = r;
	scale = s;
}

Camera_Component_Info::Camera_Component_Info(float fov, float zNear, float zFar, float aspect) {
	this->fov = fov;
	this->zFar = zFar;
	this->zNear = zNear;
	this->aspect = aspect;
}

Texture_Component_Info::Texture_Component_Info(std::string init) {
	filename = init;
}