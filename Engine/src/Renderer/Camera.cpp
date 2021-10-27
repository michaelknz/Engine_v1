#include "Camera.h"

Camera::Camera() {

}

Camera::~Camera() {

}

void Camera::Init_Entity() {

}

void Camera::Update_Entity() {
	
}

void Camera::Send_Camera_Matrixes(GLuint prog) {
	Camera_Component* cam = static_cast<Camera_Component*>(GetComponentByName("camera"));
	cam->Send_View(prog);
	cam->Send_Projection(prog);
}