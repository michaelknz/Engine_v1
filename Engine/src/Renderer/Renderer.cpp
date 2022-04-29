#include "Renderer/Renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::Init(Camera* cam) {
	shader = new Shader("DefaultShader");
	shader->Bind();
	Set_Camera(cam);
}

void Renderer::ShutUp() {
	shader->Unbind();
	delete shader;
}

void Renderer::Update(const std::map<std::string, BaseObject*>& Scene) {
	for (std::map<std::string, BaseObject*>::const_iterator i = Scene.begin(); i != Scene.end(); ++i) {
		Render_Object((*i).second);
	}
}

void Renderer::Set_Camera(Camera* cam) {
	camera = cam;
	camera->Send_Camera_Matrixes(shader->Get_Prog());
}

void Renderer::Render_Object(BaseObject* obj) {
	Mesh_Component* mesh = static_cast<Mesh_Component*>(obj->GetComponentByName(MESH_COMPONENT));
	if (mesh == nullptr) {
		return;
	}
	Texture_Component* texture = static_cast<Texture_Component*>(obj->GetComponentByName(TEXTURE_COMPONENT));
	Transform_Component* trans = static_cast<Transform_Component*>(obj->GetComponentByName(TRANSFORM_COMPONENT));
	trans->Send_Model(shader->Get_Prog());
	texture->Send_Texture(shader->Get_Prog());
	mesh->DrawMesh();
}