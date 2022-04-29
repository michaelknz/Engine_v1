#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Core/Base_Component.h"
#include "Core/Transform_Component.h"

class Camera_Component :public Base_Component {
public:
	Camera_Component();
	~Camera_Component();
	virtual void Init(Base_Info* info) override;
	virtual void Init_Dependencies(const std::map<int, Base_Component*>& comps) override;
	void Send_View(GLuint prog);
	void Send_Projection(GLuint prog);
private:
	glm::mat4 Get_View();
	glm::mat4 Get_Perspective();
	float fov;
	float zNear;
	float zFar;
	float aspect;
	Transform_Component* transform;
};


#endif