
#pragma once
#include <map>
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include <Assimp/include/assimp/Importer.hpp>
#include <Assimp/include/assimp/scene.h>
#include <Assimp/include/assimp/postprocess.h>

 
namespace OriEngine {
	class Model{
	public:
		/*  Model Data */
			// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
		std::vector<Mesh> meshes;
		std::string directory;
		const aiScene* scene;
		Shader* shaderModel;
		Model(Shader *shader);
	
		~Model();

		void Draw();
		
		void useShader();
		void useUniformMatrices(Camera* camera);
		
	
		void loadModel(std::string path);
	

		
		void processNode(aiNode* node, const aiScene* scene);
		

		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	private:
	
	


	};

}


