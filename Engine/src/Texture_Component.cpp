#include "Texture_Component.h"

Texture_Component::Texture_Component() {

}

Texture_Component::~Texture_Component() {

}

void Texture_Component::Init(Base_Info* info) {
	Texture_Component_Info* inform = static_cast<Texture_Component_Info*>(info);
	Set_Texture(inform);
}

void Texture_Component::Execute() {
	Connect_Manager* inst = Connect_Manager::get_Instace();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	inst->Send_Texture(0);
}

void Texture_Component::Set_Texture(Texture_Component_Info* init) {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	int channels;
	image = SOIL_load_image(init->filename.c_str(), &weight, &height, &channels, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, weight, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateTextureMipmap(texture);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}