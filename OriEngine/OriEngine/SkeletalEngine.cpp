#pragma once
#include "AbstractEngine.h"
#include "OpenGlRenderer.h"
#include "Sound.h"
using namespace OriEngine;
	long windowWidth = 1024;
	long windowHeight = 768;
	long windowBits = 32;
	bool fullscreen = false;
	AbstractEngine *Engine;
	HDC hDC;
	Sound* sound;

	class SkeletalEngine : public AbstractEngine
	{
	private:
		
		double lastFpsPrint = 0.0;

	public:
		SkeletalEngine()	{
		}


		virtual void postRender(){

		}

		virtual void initializeWindowingSystem()
		{
		}

		virtual void onCreate(){
			
		}

		virtual void preRender(double timeSinceLastFrame){
		
		}

	};


	void SetupPixelFormat(HDC hDC)
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

	LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		static HDC hDC;
		static HGLRC hRC;
		int height, width;
			sound = new Sound();	// window creation
			sound->init();
			sound->loadSound("03-terran-1.mp3");
			sound->playSound();
		// dispatch messages
		switch (uMsg)
		{
		case WM_CREATE:		
		
			hDC = GetDC(hWnd);
			SetupPixelFormat(hDC);
			//SetupPalette();
			hRC = wglCreateContext(hDC);
			wglMakeCurrent(hDC, hRC);
			if (glewInit() != GLEW_OK)
			{
				DebugLogger::getInstance().log(DebugLogger::FATAL_ERROR, "", "", __FILE__, __LINE__, "");
			} // wait until the window is set up before initializing glew!
			AbstractEngine::getInstance();
		
			break;

		case WM_DESTROY:			// window destroy
		case WM_QUIT:
		case WM_CLOSE:					// windows is closing

										// deselect rendering context and delete it
	//		HDApplication::getRunningApp()->stopRunning();
			wglMakeCurrent(hDC, NULL);
			wglDeleteContext(hRC);

			// send WM_QUIT to message queue
			PostQuitMessage(0);
			break;

		case WM_SIZE:
			height = HIWORD(lParam);		// retrieve width and height
			width = LOWORD(lParam);

	//		HDApplication::getRunningApp()->setWindowSize(width, height);

			break;

		case WM_ACTIVATEAPP:		// activate app
			break;

		case WM_PAINT:				// paint
			PAINTSTRUCT ps;
			BeginPaint(hWnd, &ps);
			
			EndPaint(hWnd, &ps);
			break;

		case WM_LBUTTONDOWN:		// left mouse button
			DebugLogger::getInstance().log(DebugLogger::INFO, "Main", "Main", __FILE__, __LINE__, "Click");
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
			/*if(HDApplication::getRunningApp()->deliverKeyUpEvents())
			{
			HDApplication::getRunningApp()->handleKeyUpEvent((int)wParam, (short)lParam & 0x000000000000FFFF);
			}*/
			break;

		case WM_KEYDOWN:
			int fwKeys;
			LPARAM keyData;
			fwKeys = (int)wParam;    // virtual-key code 
			keyData = lParam;          // key data 

			switch (fwKeys)
			{
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
			default:
				/*if(HDApplication::getRunningApp()->deliverKeyDownEvents())
				{
				HDApplication::getRunningApp()->handleKeyDownEvent((int)wParam, (short)lParam & 0x000000000000FFFF);
				}*/
				break;
			}

			break;

		default:
			break;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
	{
		WNDCLASS windowClass;		// window class
		HWND	   hwnd;			// window handle
		MSG		   msg;				// message
		DWORD	   dwExStyle;		// Window Extended Style
		DWORD	   dwStyle;			// Window Style
		RECT	   windowRect;

		//////////////////////////////////////////////////////////////
		// User should create the desired type of HDApplication here
		//////////////////////////////////////////////////////////////

		Engine = new SkeletalEngine();
		
		windowRect.left = (long)0;						// Set Left Value To 0
		windowRect.right = (long)800;	// Set Right Value To Requested Width
		windowRect.top = (long)0;							// Set Top Value To 0
		windowRect.bottom = (long)600;	// Set Bottom Value To Requested Height

																												// fill out the window class structure
	//	windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = MainWindowProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = hInstance;
		windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// default icon
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// default arrow
		windowClass.hbrBackground = NULL;								// don't need background
		windowClass.lpszMenuName = NULL;								// no menu
		windowClass.lpszClassName = "GLClass";
	//	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);		// windows logo small icon

																// register the windows class
		if (!RegisterClass(&windowClass))
			return 0;
		fullscreen = false;
		if (fullscreen)								// fullscreen?
		{
			DEVMODE dmScreenSettings;					// device mode
			memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
			dmScreenSettings.dmSize = sizeof(dmScreenSettings);
			dmScreenSettings.dmPelsWidth = 800;			// screen width
			dmScreenSettings.dmPelsHeight = 600;			// screen height
			dmScreenSettings.dmBitsPerPel = windowBits;				// bits per pixel
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
																		// class registered, so now create our window
		hwnd = CreateWindowEx(NULL,									// extended style
			"GLClass",							// class name
			"OriEngine",	// app name
			dwStyle | WS_CLIPCHILDREN |
			WS_CLIPSIBLINGS,
			0, 0,								// x,y coordinate
			windowRect.right - windowRect.left,
			windowRect.bottom - windowRect.top, // width, height
			NULL,								// handle to parent
			NULL,								// handle to menu
			hInstance,							// application instance
			NULL);								// no extra params

		hDC = GetDC(hwnd);

		// check if window creation failed (hwnd would equal NULL)
		if (!hwnd)
			return 0;
	
		ShowWindow(hwnd, SW_SHOW);			// display the window
		UpdateWindow(hwnd);					// update the window
		
		while (AbstractEngine::getInstance()->stillRendering())
		{	
			AbstractEngine::getInstance()->startRender();
	
			AbstractEngine::getInstance()->endRender();

			sound->update();
			SwapBuffers(hDC);
			
			while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
			{
				if (!GetMessage(&msg, NULL, 0, 0))
				{
					//HDApplication::getRunningApp()->stopRunning();
					break;
				}

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		AbstractEngine::getInstance()->cleanUp();;

		if (fullscreen)
		{
			ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
			ShowCursor(TRUE);						// Show Mouse Pointer
		}

		return (int)msg.wParam;
	}
	