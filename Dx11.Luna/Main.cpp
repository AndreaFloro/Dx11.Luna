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
#include "InitDirect3DApp.h"
#include "BoxApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//Chapter 4 - InitD3D demo
	//D3DApp* theApp = new InitDirect3DApp(hInstance);

	//Chapter 4 - InitD3D demo
	D3DApp* theApp = new BoxApp(hInstance);

	if (!theApp->Init())
		return 0;

	return theApp->Run();

	return 0;
}