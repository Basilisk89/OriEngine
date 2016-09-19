#ifndef WINDOW32_H
#define WINDOW32_H
#include <Windows.h>
class Window32{
public:
	Window32();
	~Window32();
	void init();
	void shutDown();
	void setWindowSize(const int w, const int h);
private: 
	int windowWidth;
	int windowLength;
	int windowBit;
	bool fullscreen;
	HDC* hDC;
	PIXELFORMATDESCRIPTOR pFD;
};
#endif
