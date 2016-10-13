#ifndef SHADER_PROGRAM_MANAGER_h
#define SHADER_PROGRAM_MANAGER_H
#pragma once

#include <map>

#include "Shader.h"
namespace OriEngine{
	/**
	* This is a shader program manager for shader programs residing in memory. A shader program consists of zero or mmore
	* shader components, each of which implements part of the programmable pipeline. Shader components are added to shader
	* programs and then linked to create a shader program which is ready to run. The shader components have their own
	* resource manager which looks similar to this resource manager.
	* @author R.N. Robson
	*/
	class ShaderProgramManager
	{
	public:
		/**
		* This is the type of the handle used for the resources.
		*/

	private:
		/** This is the actual resource manager storing the resources */
		static std::map<std::string, Shader*>					shaderResources;
		static ShaderProgramManager*					instance;

		/**
		* Default constructor to create empty shader program manager.
		*/
		ShaderProgramManager();

	public:
		/**
		* This is a singleton and this is the only way to create and access the single instance.
		* @return A pointer to the only instance of the class.
		*/
		static ShaderProgramManager* getInstance();

		/**
		* Destructor that deletes all shader programs from memory.
		*/
		~ShaderProgramManager();

		/**
		* This stores a shader program into the shader program manager.  This is to be used whenever a shader program has been read from
		* some external source and needs to be stored in the shader program manager.
		* @param component The shader program to store
		* @param nm The name the shader program should be stored under
		* @return a handle to the stored resource
		* @throws DuplicateNameException if the name is already in use
		*/
		static Shader* storeShaderProgram(Shader *component, const std::string &handle);

		/**
		* Given the name a shader program was stored under, this will
		* return a pointer to the shader program.
		* @param nm The name of the resource to retrieve.
		* @return A handle to the shader program requested.
		* @throws IndexOutOfBoundsException if the name is not found.
		*/
		//HandleType getShaderHandle(const std::string &nm) const;

		/**
		* Given the handle to a shader program under the control of the shader program manager, this will
		* return a pointer to the shader program.
		* @param handle The handle of the resource to retrieve.
		* @return A pointer to the shader program requested.
		* @throws IndexOutOfBoundsException if the handle is not valid.
		*/
		static Shader* getShader(const std::string &handle);
		static void handleUniforms(char* projectionMatrix, char* modelviewMatrix, char* normalMatrix, char* lightPos, const std::string &handle);
		/**
		* This deletes a shader program from the shader program manager. It will also release
		* the component from the GPU if it has been compiled.
		* @param resName The resource name for the shader component to delete.
		* @throws IndexOutOfBoundsException if the materrial does not exist.
		*/
		void deleteShaderProgram(const std::string& resName);
		void clearManager();
	};
}
#endif


