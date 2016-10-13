#include "ShaderManager.h"
#include "DebugLogger.h"
using namespace OriEngine;
ShaderProgramManager* ShaderProgramManager::instance = nullptr;
std::map<std::string, Shader*> ShaderProgramManager::shaderResources;
ShaderProgramManager* ShaderProgramManager::getInstance(){
	if (instance == nullptr){
		instance = new ShaderProgramManager();
	}
	return instance;
}
ShaderProgramManager::ShaderProgramManager(){
}
ShaderProgramManager::~ShaderProgramManager(){
}
Shader* ShaderProgramManager::storeShaderProgram(Shader *mat, const std::string &handle){
	shaderResources[handle] = mat;
	if (shaderResources[handle] == nullptr ) {
		return nullptr;
	}
	return shaderResources[handle];
}
Shader* ShaderProgramManager::getShader(const std::string &handle) {
	Shader *result = shaderResources.at(handle);
	if (result == nullptr){
		return nullptr;
	}
	return result;
}
void ShaderProgramManager::deleteShaderProgram(const std::string& resName){
	delete shaderResources[resName];
	shaderResources[resName] = nullptr;
}
void ShaderProgramManager::clearManager() {
	shaderResources.clear();
}