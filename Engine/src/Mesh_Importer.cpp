#include "Mesh_Importer.h"

VertInfo::VertInfo() {
	isNormals = false;
	isPos = false;
	isUV = false;
}

Mesh_Importer::Mesh_Importer() {

}

Mesh_Importer::~Mesh_Importer() {

}

VertInfo Mesh_Importer::LoadVertices(const std::string& file_name) {
	Assimp::Importer importer;
	const aiScene* Scene = importer.ReadFile(file_name, aiProcess_Triangulate);
	aiMesh* mesh = Scene->mMeshes[0];

	VertInfo output;
	output.isNormals = false;
	output.isPos = false;
	output.isUV = false;

	if (mesh->mVertices != NULL) {
		output.isPos = true;
	}

	if (mesh->mTextureCoords[0] != NULL) {
		output.isUV = true;
	}

	if (mesh->mNormals != NULL) {
		output.isNormals = true;
	}

	for (int i = 0; i < mesh->mNumFaces; ++i) {
		const aiFace& face = mesh->mFaces[i];
		for (int j = 0; j < face.mNumIndices; ++j) {
			unsigned int index = face.mIndices[j];
			if (output.isPos) {
				aiVector3D pos = mesh->mVertices[index];
				output.vertices.push_back(pos.x);
				output.vertices.push_back(pos.y);
				output.vertices.push_back(pos.z);
			}
			if (output.isNormals) {
				aiVector3D norm = mesh->mNormals[index];
				output.vertices.push_back(norm.x);
				output.vertices.push_back(norm.y);
				output.vertices.push_back(norm.z);

			}
			if (output.isUV) {
				aiVector3D UVs = mesh->mTextureCoords[0][index];
				output.vertices.push_back(UVs.x);
				output.vertices.push_back(UVs.y);
			}
		}
	}

	importer.FreeScene();
	return output;

}