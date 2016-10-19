#pragma once
#include <map>
#include "Image.h"
namespace OriEngine {
	class ImgManager
	{
	public:

		ImgManager* getinstance();
		void storeImage(Image* image, std::string  name);
		Image* getImage(std::string name);
		void deleteImage(std::string name);
		void clear();
		~ImgManager();
	private:
		ImgManager();
		static ImgManager* imgManagerInstance;
		static std::map<std::string, Image*> imgMap;
	};
}
