#include "Mesh_Component.h"

Mesh_Component::Mesh_Component() {

	mesh = new Mesh();

}

Mesh_Component::~Mesh_Component() {
	delete mesh;
}

void Mesh_Component::SetMesh(const std::string& file_name) {
	mesh->SetMesh(importer.LoadVertices(file_name));
}

void Mesh_Component::DrawMesh() {
	mesh->DrawMesh();
}

void Mesh_Component::Init(Base_Info* info) {
	Mesh_Component_Info* inf = static_cast<Mesh_Component_Info*>(info);
	SetMesh(inf->filename);
}