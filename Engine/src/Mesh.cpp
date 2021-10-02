#include "Mesh.h"

Mesh::Mesh() {

	BufSize = 0;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

}

Mesh::~Mesh() {
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void Mesh::SetMesh(VertInfo vertices) {
	BufSize = vertices.vertices.size();

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, BufSize * sizeof(float), &vertices.vertices[0], GL_STATIC_DRAW);

	int line_size = (int)vertices.isPos * 3 + (int)vertices.isNormals * 3 + (int)vertices.isUV * 2;
	int del_size = 0;

	if (vertices.isPos) {
		glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, line_size * sizeof(float), (GLvoid*)(del_size*sizeof(float)));
		glEnableVertexAttribArray(POSITION);
		del_size += 3;
	}

	if (vertices.isNormals) {
		glVertexAttribPointer(NORMALS, 3, GL_FLOAT, GL_FALSE, line_size * sizeof(float), (GLvoid*)(del_size * sizeof(float)));
		glEnableVertexAttribArray(NORMALS);
		del_size += 3;
	}

	if (vertices.isUV) {
		glVertexAttribPointer(UV_COORDS, 2, GL_FLOAT, GL_FALSE, line_size * sizeof(float), (GLvoid*)(del_size * sizeof(float)));
		glEnableVertexAttribArray(UV_COORDS);
		del_size += 2;
	}

	glBindVertexArray(0);
}

void Mesh::DrawMesh() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, BufSize);
	glBindVertexArray(0);
}