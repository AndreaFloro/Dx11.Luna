#pragma once
#include "D:\Source\Repository\Dx11.Luna\Common\d3dApp.h"
class InitDirect3DApp :
	public D3DApp
{
public:
	InitDirect3DApp(HINSTANCE hInstance);
	~InitDirect3DApp();

	// Inherited via D3DApp
	virtual void UpdateScene(float dt) override;
	virtual void DrawScene() override;
};

