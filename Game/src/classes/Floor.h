#ifndef FLOOR_H
#define FLOOR_H

#include <Engine.h>

class Floor :public BaseObject {
public:
	Floor();
	~Floor();
	virtual void Init_Entity() override;
	virtual void Update_Entity() override;
};

#endif