#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include <glew.h>
#include <string>
#include "Renderer/Mesh.h"
#include "Renderer/Mesh_Importer.h"
#include "Core/Base_Component.h"

class Mesh_Component:public Base_Component {
public:
	Mesh_Component();
	~Mesh_Component();

	void SetMesh(const std::string& file_name);
	void DrawMesh();
	virtual void Init(Base_Info* info) override;
	virtual void Execute() override;
private:
	Mesh_Importer importer;
	Mesh* mesh;
};

#endif
