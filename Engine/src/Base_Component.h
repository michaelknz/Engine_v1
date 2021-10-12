#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

#include <glew.h>
#include "Component_Structs.h"

class Base_Component {
public:
	Base_Component();
	~Base_Component();
	virtual void Execute();
	virtual void Init(Base_Info* info);
};

#endif