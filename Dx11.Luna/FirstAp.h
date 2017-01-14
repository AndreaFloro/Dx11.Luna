#pragma once
#include "d3dApp.h"

class FirstAp : public D3DApp
{
public:
	FirstAp(HINSTANCE hInstance);
	~FirstAp();

	// Inherited via D3DApp
	virtual void UpdateScene(float dt) override;
	virtual void DrawScene() override;
};

