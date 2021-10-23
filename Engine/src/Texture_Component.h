#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <SOIL.h>
#include <glew.h>
#include "Base_Component.h"
#include "Connect_Manager.h"

class Texture_Component :public Base_Component {
public:
	Texture_Component();
	~Texture_Component();
	virtual void Init(Base_Info* info) override;
	virtual void Execute() override;
	void Set_Texture(Texture_Component_Info* init);
private:
	GLuint texture;
	unsigned char* image;
	int weight, height;
};

#endif