#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include <iostream>
#include <glew-2.0.0\include\GL\glew.h>
#include <Windows.h>
#include <AlienFX SDK\Unmanaged\includes\LFX2.h>
#include "Clock.h"
#include "AbstractEngine.h"
#include "DebugLogger.h"
#include "Model.h"
using namespace OriEngine;
long windowWidth = 1024;
long windowHeight = 768;
long windowBits = 32;
bool fullscreen = false;

AbstractEngine* engine;
Model* model;
HDC hDC;
Camera* camera;

class MainGame : public AbstractEngine{
private:

	double lastFpsPrint = 0.0;

public:
	MainGame(){

	}


	virtual void postRender(){

	}

	virtual void initializeWindowingSystem(){
	}

	virtual void onCreate(){
	//	AbstractEngine::getInstance()->renderer.init();
	
		AbstractEngine::getInstance()->musicSystem.createSounds("C:/Users/Ryan/Documents/GitHub/OriEngine/OriEngine/OriEngineResources/FFXIV_OST_The_Fractal_Continuum_Theme.mp3", 1);
		AbstractEngine::getInstance()->musicSystem.playSounds(1);
	}

	virtual void preRender(double timeSinceLastFrame){
	}

};


void SetupPixelFormat(HDC hDC){
	int pixelFormat;

	PIXELFORMATDESCRIPTOR pfd ={
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
void deleteContext(HDC hDC, HGLRC hGLRC) {
	if (hDC && hGLRC) {
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hGLRC);
	}
}
void createContext(HDC hDC, HGLRC hGLRC) {
		hGLRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hGLRC);
}
bool InitGL() {
	if (glewInit() != GLEW_OK) {
		MessageBoxA(0, "GLEW failed to load", "OriEngine", 0);
		DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "SkeletalEngine.cpp", "InitGL", __FILE__, __LINE__, "Glew Failed to Initialize");
		return false;
	}else {
		MessageBoxA(NULL, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
		DebugLogger::getInstance().log(DebugLogger::INFO, "SkeletalEngine.cpp", "InitGL", __FILE__, __LINE__, "Glew Started");
		return true;
	}
	
}

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	static HDC hDC;
	static HGLRC hRC;
	int height, width;

	// dispatch messages
	switch (uMsg){
	case WM_CREATE:			// window creation
		hDC = GetDC(hWnd);
		SetupPixelFormat(hDC);
	
		createContext(hDC, hRC);

		InitGL();
		break;

	case WM_DESTROY:			// window destroy
	case WM_QUIT:
	
		exit(0);
		break;
	case WM_CLOSE:					// windows is closing


		deleteContext(hDC, hRC);

		MessageBoxA(hWnd, "Quiting?", "OriEngine", 0);
		// send WM_QUIT to message queue
		PostQuitMessage(0);
		exit(0);
		break;

	case WM_SIZE:
		height = HIWORD(lParam);		// retrieve width and height
		width = LOWORD(lParam);

		break;

	case WM_ACTIVATEAPP:		// activate app
		break;

	case WM_PAINT:				// paint
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:		// left mouse button
		break;

	case WM_RBUTTONDOWN:		// right mouse button
		break;

	case WM_MOUSEMOVE:			// mouse movement
		break;

	case WM_LBUTTONUP:			// left button release
		break;

	case WM_RBUTTONUP:			// right button release
		break;

	case WM_KEYUP:

		break;

	case WM_KEYDOWN:
		int fwKeys;
		LPARAM keyData;
		fwKeys = (int)wParam;    // virtual-key code 
		keyData = lParam;          // key data 

		switch (fwKeys){
		case VK_ESCAPE:
			PostQuitMessage(0);
			exit(0);
			break;	
		default:
			/*if(GeEngine::getRunningApp()->deliverKeyDownEvents())
			{
			GeEngine::getRunningApp()->handleKeyDownEvent((int)wParam, (short)lParam & 0x000000000000FFFF);
			}*/
			break;
		}

		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
void gameLoop(MSG msg) {
	while (true) {
		AbstractEngine::getInstance()->startRender();
	
		AbstractEngine::getInstance()->endRender();
		AbstractEngine::getInstance()->musicSystem.updateSounds();
		SwapBuffers(hDC);

		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
			if (!GetMessage(&msg, NULL, 0, 0)) {
				//GeEngine::getRunningApp()->stopRunning();
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
HWND CreateGLWindow(DWORD dwStyle,RECT windowRectangle,HINSTANCE hInstance,const char* className, const char* windowName) {
	HWND tmphWnd;
	tmphWnd = CreateWindowEx(NULL, className, windowName, dwStyle | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, windowRectangle.right - windowRectangle.left, windowRectangle.bottom - windowRectangle.top, NULL, NULL, hInstance, NULL);
	if (!tmphWnd) {return NULL;}
	else{return tmphWnd;}
}
WNDCLASSEX setWindowClass( UINT style, HINSTANCE hInstance) {
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = MainWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// default icon
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// default arrow
	windowClass.hbrBackground = NULL;								// don't need background
	windowClass.lpszMenuName = "Options";								// no menu
	windowClass.lpszClassName = "GLClass";
	windowClass.hIconSm = (HICON)LoadImage(GetModuleHandle(0), "C: / Users / Ryan / Documents / GitHub / OriEngine / OriEngine / OriEngineResources / V.ico", IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR);	// windows logo small icon
	return windowClass;
}
RECT getWindowRect(int width, int height) {
	RECT windowRect;
	windowRect.left = (long)0;						// Set Left Value To 0
	windowRect.right = width;	// Set Right Value To Requested Width
	windowRect.top = (long)0;							// Set Top Value To 0
	windowRect.bottom = height;
	return windowRect;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	WNDCLASSEX windowClass;		// window class
	HWND	   hwnd;			// window handle
	MSG		   msg;				// message
	DWORD	   dwExStyle;		// Window Extended Style
	DWORD	   dwStyle;			// Window Style
	RECT	   windowRect;

	//////////////////////////////////////////////////////////////
	// User should create the desired type of GeEngine here
	//////////////////////////////////////////////////////////////

	engine = new MainGame();

	windowRect = getWindowRect(800, 400);
				
	windowClass = setWindowClass(CS_HREDRAW | CS_VREDRAW, hInstance);
															// register the windows class
	if (!RegisterClassEx(&windowClass))
		return 0;

	fullscreen = false;

	if (fullscreen){
		DEVMODE dmScreenSettings;					// device mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = 800;			// screen width
		dmScreenSettings.dmPelsHeight = 400;			// screen height
		dmScreenSettings.dmBitsPerPel = windowBits;				// bits per pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// 
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL){
			// setting display mode failed, switch to windowed
			MessageBox(NULL, "Display mode failed", NULL, MB_OK);
			fullscreen = FALSE;
		}
	}

	if (fullscreen){
		dwExStyle = WS_EX_APPWINDOW;					// Window Extended Style
		dwStyle = WS_POPUP;						// Windows Style
		ShowCursor(FALSE);						// Hide Mouse Pointer
	}else{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;					// Windows Style
	}

	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size
	hwnd = CreateGLWindow(dwStyle, windowRect, hInstance, "GLClass", "OriEngine");
	hDC = GetDC(hwnd);

	// check if window creation failed (hwnd would equal NULL)
	if (!hwnd) 
		exit(0);
	if(hwnd)
		engine->onCreate();
	Vec4 light = Vec4(-0.0, 5.0, -0.0, 0.0);;
	
	ShowWindow(hwnd, SW_SHOW);			// display the window
	UpdateWindow(hwnd);					// update the window
	while (true) {
		AbstractEngine::getInstance()->startRender();

		AbstractEngine::getInstance()->endRender();
		AbstractEngine::getInstance()->musicSystem.updateSounds();
		SwapBuffers(hDC);

		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
			if (!GetMessage(&msg, NULL, 0, 0)) {
				//GeEngine::getRunningApp()->stopRunning();
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	//GeEngine::getRunningApp()->shutdown();
	if (fullscreen){
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);						// Show Mouse Pointer
	}
	return (int)msg.wParam;
}
