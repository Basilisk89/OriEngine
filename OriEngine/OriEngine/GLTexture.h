#pragma once
#include "Image.h"
namespace OriEngine {
	class GLTexture :
		public Image
	{
	public:
		GLTexture();
		~GLTexture();
		void loadTexture(std::string filename);
		GLuint initGLTexture();
		Image *image;
	};
}

