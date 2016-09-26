#ifndef WINDOW32_H
#define WINDOW32_H
#include <Windows.h>
#include "DebugLogger.h"
namespace OriEngine {
	class Window32 {
	public:
	
		void getInstance();

		void cleanUp();
		Window32();
		~Window32();
		HWND createWindow(HWND hWnd,HINSTANCE hi);
		void fullScreen(bool setFullScreen);
		void windowUpdate(HWND hwnd);
		void swapBuffers(HDC hdc);
		HDC getHDC();
		HWND getHWND() const;
		void showWindow(HWND hwnd, int show);
		void setPixelFormat();
		void createContext();
		void deleteContext();
		void setWindowSize(int width, int height);
		bool initWindowClass(WNDPROC l, HINSTANCE hi);
	
		bool peekMessage(MSG &msg);
		void setDC(HWND hWnd);
		void setHWND(HWND hwnd);
	private:

		int windowWidth;
		int windowHeight;
		int windowBit;
		bool fullscreen;
		HDC hDC;
		HGLRC hRC;
		PIXELFORMATDESCRIPTOR pFD;
		WNDCLASS windowClass;
		HWND hWnd;
		
		DWORD dwExStyle, dwStyle;
		RECT windowRect;
		DEVMODE dmScreenSettings;
	protected:
	};
}
#endif
