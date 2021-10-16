#ifndef CAMERA_H
#define CAMERA_H

#include "Base_Object.h"
#include "Camera_Component.h"


class Camera : public BaseObject {
public:
	Camera();
	~Camera();
	virtual void Init_Entity() override;
	virtual void Update_Entity() override;
};

#endif