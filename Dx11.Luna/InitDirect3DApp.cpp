#include "InitDirect3DApp.h"
#include "d3dUtil.h"


InitDirect3DApp::InitDirect3DApp(HINSTANCE hInstance)
	:D3DApp(hInstance)
{
}


InitDirect3DApp::~InitDirect3DApp()
{
}

void InitDirect3DApp::UpdateScene(float dt)
{
}

void InitDirect3DApp::DrawScene()
{
	assert(md3dImmediateContext);
	assert(mSwapChain);

	//Clear the back buffer to blue
	md3dImmediateContext->ClearRenderTargetView(mRenderTargetView, reinterpret_cast<const float*>(&Colors::Blue));

	//Clear the depth buffer to 1.0f and the stencil buffer to 0.0f
	md3dImmediateContext->ClearDepthStencilView(mDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0.0f);

	//Present the backbuffer
	HR(mSwapChain->Present(0, 0));
}
