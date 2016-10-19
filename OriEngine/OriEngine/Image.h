#pragma once
#include <FreeImage\Dist\x32\FreeImage.h>
#include <string>
#include "DebugLogger.h"
#include "ImageLoader.h"
#include <glew-2.0.0\include\GL\glew.h>
namespace OriEngine {
	class Image {
	public:
		Image() :image(nullptr) {

		}
		~Image() {
			deleteImage();
		}
		Image* operator=(Image* image) {
			Image* result;
			result->image = image->image;
			result->imageFormat = image->imageFormat;
			result->h = image->h;
			result->w = image->w;
			return result;
		}
		void loadImage(std::string fileName) {
			imageFormat = FreeImage_GetFileType(fileName.c_str());
			image = FreeImage_Load(imageFormat, fileName.c_str(), 1);
			w = FreeImage_GetWidth(image);
			h = FreeImage_GetHeight(image);
		}
		void deleteImage() {
			image = nullptr;
			delete image;
		}
		GLubyte* getImageBytes() {
			GLubyte *result;
			result = FreeImage_GetBits(image);
			return result;
		}
		FREE_IMAGE_FORMAT imageFormat;
		FIBITMAP* image;
		int w, h;
	};
}