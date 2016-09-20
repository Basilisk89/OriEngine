#ifndef WINDOW32_H
#define WINDOW32_H
#include <Windows.h>
#include "DebugLogger.h"
class Window32{
public:
	~Window32();
	void getInstance();
	void init();
	void cleanUp();
	void setWindowSize(const int w, const int h);
	void SetupPixelFormat(HDC hdc);
	HWND createWindow(std::string windowName, RECT _windowRect);
	void fullScreen(bool setFullScreen);
	void windowUpdate(HWND hwnd);
	void swapBuffers(HDC hdc);
	void showWindow(HWND hwnd, int show);
private: 
	Window32();
	int windowWidth;
	int windowLength;
	int windowBit;
	bool fullscreen;
	HDC* hDC;
	PIXELFORMATDESCRIPTOR pFD;
	WNDCLASSEX windowClass;
	HWND hWND;
	MSG msg;
	DWORD dwExStyle,dwStyle;
	RECT windowRect;
	DEVMODE dmScreenSettings;
protected:
};
#endif
