//Include rules
//General
//Output directory: $(SolutionDir)bin\$(Platform)\$(Configuration)\
//Intermediate directory: $(Platform)\tmp\$(Configuration)\
//C++
//Additional Include Directories: $(SolutionDir)Common;%(AdditionalIncludeDirectories)
//Linker
//Additional Linker Directories: $(SolutionDir)Common
//Included lib x64 debug
//d3d11.lib
//D3DCompiler.lib
//Effects11d.lib
//dxgi.lib
//dxguid.lib

#if _WIN32 || _WIN64
#if _WIN64
#if defined(DEBUG) || defined(_DEBUG)
//x64 DEBUG
#pragma comment(lib, "../Common/Effects11d")
#pragma comment(lib, "d3d11")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "D3DCompiler")
#else
//x64 RELEASE
#pragma comment(lib, "Effects11")
#endif
#else
#if defined(DEBUG) || defined(_DEBUG)
//WIN32 (x86) DEBUG
#else
//WIN32 (x86) RELEASE
#endif
#endif // _WIN64
#endif


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

#include "HillsDemoApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	D3DApp* theApp = new HillsDemoApp(hInstance);

	if (!theApp->Init())
		return 0;

	return theApp->Run();

	return 0;
}