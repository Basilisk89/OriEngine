#pragma once
#include "Image.h"
namespace OriEngine {
	class ImageLoader {
	public:
		static FREE_IMAGE_FORMAT loadImageFormat(std::string fileName) {
			FREE_IMAGE_FORMAT imageFormat;
			imageFormat = FreeImage_GetFileType(fileName.c_str(), 0);
			return imageFormat;
		}
		static FIBITMAP* loadImageFile(FREE_IMAGE_FORMAT imageFormat, std::string fileName) {
			FIBITMAP* imageBitmap;
			imageBitmap = FreeImage_Load(imageFormat, fileName.c_str());
			return imageBitmap;
		}

	};
}