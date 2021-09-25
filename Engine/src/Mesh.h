#ifndef MESH_H
#define MESH_H

#include <glew.h>

class Mesh {
public:
	Mesh(float* VertexBuf, unsigned int size, unsigned int line_size);
	~Mesh();
	void DrawMesh();
private:
	GLuint vao;
	GLuint vbo;
	unsigned int BufSize;
};

#endif