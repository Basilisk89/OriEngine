#include "GLTexture.h"
#include <cstdio>
#include "DebugLogger.h"
using namespace OriEngine;

GLTexture::GLTexture() :image(new Image())
{
}


GLTexture::~GLTexture()
{
}

void OriEngine::GLTexture::loadTexture(std::string filename){
	image->loadImage(filename);
}

GLuint OriEngine::GLTexture::initGLTexture(){
	GLubyte* textureData = image->getImageBytes();

	// Generate a texture ID and bind to it
	GLuint tempTextureID;
	glGenTextures(1, &tempTextureID);
	glBindTexture(GL_TEXTURE_2D, tempTextureID);
	glTexImage2D(GL_TEXTURE_2D,    // Type of texture
		0,                // Mipmap level (0 being the top level i.e. full size)
		GL_RGBA,          // Internal format
		image->w,       // Width of the texture
		image->h,      // Height of the texture,
		0,                // Border in pixels
		GL_BGRA,          // Data format
		GL_UNSIGNED_BYTE, // Type of texture data
		textureData);
	GLenum glError = glGetError();
	if (glError)
	{
		//std::cout << "There was an error loading the texture: " << filenameString << endl;
		DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "GLTexture", "GLinitTexture", __FILE__, __LINE__, "Error loading Texture" + std::string());
		switch (glError)
		{
		case GL_INVALID_ENUM:
			DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "GLTexture", "GLinitTexture", __FILE__, __LINE__, "Error loading Texture" + std::string());
			break;

		case GL_INVALID_VALUE:
			DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "GLTexture", "GLinitTexture", __FILE__, __LINE__, "Error loading Texture" + std::string());
			break;

		case GL_INVALID_OPERATION:
			DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "GLTexture", "GLinitTexture", __FILE__, __LINE__, "Error loading Texture" + std::string());

		default:
			DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "GLTexture", "GLinitTexture", __FILE__, __LINE__, "Error loading Texture" + std::string());
			break;
		}

	}
	return tempTextureID;

}
