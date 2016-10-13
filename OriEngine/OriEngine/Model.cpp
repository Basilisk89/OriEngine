#include "Model.h"
using namespace OriEngine;
Model::Model(Shader* shader)
{
	shaderModel = shader;
}

Model::~Model()
{
	delete scene;
}

void Model::Draw()
{
	for (GLuint i = 0; i < this->meshes.size(); i++)
		meshes[i].Draw();
}

void Model::processNode(aiNode * node, const aiScene * scene)
{
	// Process each mesh located at the current node
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		// The node object only contains indices to index the actual objects in the scene. 
		// The scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	// After we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh * mesh, const aiScene * scene)
{
	// Data to fill
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;


	// Walk through each of the mesh's vertices
	for (GLuint i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;

		Vec3 vector;
		Vec3 normaltmp;			 // Positions
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		
		vertex.Position = vector;
		// Normals
		normaltmp.x = mesh->mNormals[i].x;
		normaltmp.y = mesh->mNormals[i].y;
		normaltmp.z = mesh->mNormals[i].z;
		vertex.Normal = normaltmp;

		vertices.push_back(vertex);
	}
	// Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		// Retrieve all indices of the face and store them in the indices vector
		for (GLuint j = 0; j < face.mNumIndices; j++) {
			indices.push_back(face.mIndices[j]);
		}
	}

	return Mesh(vertices, indices);
	// Return a mesh object created from the extracted mesh data
	
}
void Model::useShader() {
	glUseProgram(shaderModel->getShader());
	}
void Model::useUniformMatrices(Camera* camera) {
	glUniformMatrix4fv(shaderModel->getStdUniformLoc(Shader::PROJECTION_MATRIX), 1, GL_FALSE, camera->getMatrixfv(PROJECTION));
	glUniformMatrix4fv(shaderModel->getStdUniformLoc(Shader::MODELVIEW_MATRIX), 1, GL_FALSE, camera->getMatrixfv(MODELVIEW));
	glUniformMatrix3fv(shaderModel->getStdUniformLoc(Shader::NORMAL_MATRIX), 1, GL_FALSE, camera->getMatrixfv(NORMAL));

}
void Model::loadModel(std::string path){
	// Read file via ASSIMP
	Assimp::Importer importer;
	scene = importer.ReadFile(path, 
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);
	// Check for errors
	if (!scene ){
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	// Retrieve the directory path of the filepath
	directory = path.substr(0, path.find_last_of('/'));

		// Process ASSIMP's root node recursively
		processNode(scene->mRootNode, scene);
	
}


