#ifndef MESH_STRUCTS_H
#define MESH_STRUCTS_H

#include <vector>

struct VertInfo {
	std::vector<float> vertices;
	bool isPos;
	bool isUV;
	bool isNormals;
	VertInfo();
};

#endif
