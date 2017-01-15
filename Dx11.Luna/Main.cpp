#ifndef _WINDOWS_
#include <Windows.h>
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "d3dApp.h"
//InitD3D demo
//#include "InitDirect3DApp.h"
//Drawing in Direct3D - Box demo
//#include "BoxApp.h"
//Drawing in Direct3D - Hills demo
//#include "HillsDemo.h"
//Drawing in Direct3D - Shapes demo
#include "ShapesApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//InitD3D demo
	//D3DApp* theApp = new InitDirect3DApp(hInstance);

	//Drawing in Direct3D - Box demo
	//D3DApp* theApp = new BoxApp(hInstance);

	//Drawing in Direct3D - Hills demo
	//D3DApp* theApp = new HillsDemo(hInstance);

	//Drawing in Direct3D - Shapes demo
	D3DApp* theApp = new ShapesApp(hInstance);

	if (!theApp->Init())
		return 0;

	return theApp->Run();

	return 0;
}