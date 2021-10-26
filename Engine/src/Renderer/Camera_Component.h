#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Core/Base_Component.h"
#include "Core/Transform_Component.h"
#include "Core/Connect_Manager.h"

class Camera_Component :public Base_Component {
public:
	Camera_Component();
	~Camera_Component();
	virtual void Init(Base_Info* info) override;
	virtual void Execute() override;
	virtual void Init_Dependencies(std::map<std::string, Base_Component*> comps) override;
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