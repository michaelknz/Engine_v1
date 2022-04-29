#ifndef COMPONENT_STRUCTS_H
#define COMPONENT_STRUCTS_H

#include <string>
#include <glm.hpp>

struct Base_Info {

};

enum {
	TRANSFORM_COMPONENT,
	MESH_COMPONENT,
	CAMERA_COMPONENT,
	TEXTURE_COMPONENT
};

struct Color {
	Color(float r, float g, float b, float a);
	float red;
	float green;
	float blue;
	float alpha;
};

struct Mesh_Component_Info:public Base_Info {
	Mesh_Component_Info(std::string init);
	std::string filename;
};

struct Transform_Component_Info :public Base_Info {
	Transform_Component_Info(glm::vec3 p, glm::vec3 r, glm::vec3 s);
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

struct Camera_Component_Info :public Base_Info {
	Camera_Component_Info(float fov, float zNear, float zFar, float aspect);
	float fov;
	float zNear;
	float zFar;
	float aspect;
};

struct Texture_Component_Info : public Base_Info {
	Texture_Component_Info(std::string init);
	std::string filename;
};

#endif
