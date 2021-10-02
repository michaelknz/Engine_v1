#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include "Mesh_Structs.h"

class Mesh {
public:
	Mesh();
	void SetMesh(VertInfo vertices);
	~Mesh();
	void DrawMesh();
private:
	GLuint vao;
	GLuint vbo;
	enum VertIndices {
		POSITION,
		NORMALS,
		UV_COORDS
	};
	unsigned int BufSize;
};

#endif