#include "Window32.h"
using namespace OriEngine;

void OriEngine::Window32::setDC(HWND hWnd){
	hDC = GetDC(hWnd);
}

void OriEngine::Window32::setHWND(HWND hwnd)
{
	hWnd = hwnd;
}

void OriEngine::Window32::showWindow(HWND hwnd, int show)
{
		ShowWindow(hwnd, show);	
}

void OriEngine::Window32::setPixelFormat()
{
	int pixelFormat;

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),	// size
		1,							// version
		PFD_SUPPORT_OPENGL |		// OpenGL window
		PFD_DRAW_TO_WINDOW |		// render to window
		PFD_DOUBLEBUFFER,			// support double-buffering
		PFD_TYPE_RGBA,				// color type
		32,							// prefered color depth
		0, 0, 0, 0, 0, 0,			// color bits (ignored)
		0,							// no alpha buffer
		0,							// alpha bits (ignored)
		0,							// no accumulation buffer
		0, 0, 0, 0,					// accum bits (ignored)
		16,							// depth buffer
		0,							// no stencil buffer
		0,							// no auxiliary buffers
		PFD_MAIN_PLANE,				// main layer
		0,							// reserved
		0, 0, 0,					// no layer, visible, damage masks
	};

	pixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, pixelFormat, &pfd);
}

void OriEngine::Window32::createContext()
{
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);
}

void OriEngine::Window32::deleteContext()
{
	wglMakeCurrent(hDC, NULL);
	wglDeleteContext(hRC);
}

void OriEngine::Window32::setWindowSize(int width, int height )
{
	windowWidth = width;
	windowHeight = height;
	windowBit = 32;
}

bool OriEngine::Window32::initWindowClass(WNDPROC l,HINSTANCE hi)
{

	windowRect.left = (long)0;						// Set Left Value To 0
	windowRect.right = (long)windowWidth;	// Set Right Value To Requested Width
	windowRect.top = (long)0;							// Set Top Value To 0
	windowRect.bottom = (long)windowHeight;	// Set Bottom Value To Requested Height

									// fill out the window class structure
									//	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = l;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hi;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// default icon
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// default arrow
	windowClass.hbrBackground = NULL;								// don't need background
	windowClass.lpszMenuName = NULL;								// no menu
	windowClass.lpszClassName = "GLClass";
	//	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);		// windows logo small icon

	// register the windows class
	if (!RegisterClass(&windowClass))
		return false;
	else
		return true;
}

OriEngine::Window32::Window32()
{
}

OriEngine::Window32::~Window32()
{
}

HWND OriEngine::Window32::createWindow(HWND hWnd,HINSTANCE hi)
{
	
	HWND result = CreateWindowEx(NULL,									// extended style
		"GLClass",							// class name
		"OriEngine",	// app name
		dwStyle | WS_CLIPCHILDREN |
		WS_CLIPSIBLINGS,
		0, 0,								// x,y coordinate
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top, // width, height
		NULL,								// handle to parent
		NULL,								// handle to menu
		hi,							// application instance
		NULL);
	setDC(hWnd);
	/*fullscreen = false;
	if (fullscreen)								// fullscreen?
	{
	DEVMODE dmScreenSettings;					// device mode
	memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
	dmScreenSettings.dmSize = sizeof(dmScreenSettings);
	dmScreenSettings.dmPelsWidth = 800;			// screen width
	dmScreenSettings.dmPelsHeight = 600;			// screen height
	dmScreenSettings.dmBitsPerPel = 32;				// bits per pixel
	dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

	//
	if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
	{
	// setting display mode failed, switch to windowed
	MessageBox(NULL, "Display mode failed", NULL, MB_OK);
	fullscreen = FALSE;
	}
	}

	if (fullscreen)								// Are We Still In Fullscreen Mode?
	{
	dwExStyle = WS_EX_APPWINDOW;					// Window Extended Style
	dwStyle = WS_POPUP;						// Windows Style
	ShowCursor(FALSE);						// Hide Mouse Pointer
	}
	else
	{
	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
	dwStyle = WS_OVERLAPPEDWINDOW;					// Windows Style
	}
	
	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size
	*/
	if (result)
		return HWND(result);
	else
		return NULL;
}

void OriEngine::Window32::windowUpdate(HWND hwnd)
{
UpdateWindow(hwnd);	
}

void OriEngine::Window32::swapBuffers(HDC hdc)
{
	SwapBuffers(hdc);
}

HDC OriEngine::Window32::getHDC()
{
	return HDC(hDC);
}

HWND OriEngine::Window32::getHWND() const
{
	return HWND(hWnd);
}
