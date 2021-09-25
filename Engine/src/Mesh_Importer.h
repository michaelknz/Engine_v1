#ifndef MESH_IMPORTER_H
#define MESH_IMPORTER_H

#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct VertInfo {
	std::vector<float> vertices;
	bool isPos;
	bool isUV;
	bool isNormals;
	VertInfo();
};

class Mesh_Importer {
public:
	Mesh_Importer();
	~Mesh_Importer();
	VertInfo LoadVertices(const std::string& file_name);
};

#endif
