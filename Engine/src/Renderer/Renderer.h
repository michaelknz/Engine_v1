#ifndef RENDERER_H
#define RENDERER_H

#include "Renderer/Shader.h"
#include "Renderer/Camera.h"
#include "Core/Base_Object.h"
#include "Renderer/Mesh_Component.h"
#include "Renderer/Texture_Component.h"

class Renderer {
public:
	Renderer();
	~Renderer();
	void Init(Camera* cam);
	void Update(const std::map<std::string, BaseObject*>& Scene);
	void Render_Object(BaseObject* obj);
	void Set_Camera(Camera* cam);
	void ShutUp();
private:
	Shader* shader;
	Camera* camera;
};

#endif
