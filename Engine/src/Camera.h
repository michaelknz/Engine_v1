#ifndef CAMERA_H
#define CAMERA_H

#include "Base_Object.h"
#include "Camera_Component.h"


class Camera : public BaseObject {
public:
	Camera(Transform_Component_Info* inf);
	~Camera();
	virtual void Init_Entity() override;
	virtual void Update_Entity() override;
};

#endif