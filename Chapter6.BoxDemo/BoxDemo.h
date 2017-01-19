#pragma once
#include "D:\Source\Repository\Dx11.Luna\Common\d3dApp.h"
#include "d3dx11effect.h"
#include "MathHelper.h"

struct Vertex
{
	DirectX::XMFLOAT3 Pos;
	DirectX::XMFLOAT4 Color;
};

class BoxDemo :
	public D3DApp
{
public:
	BoxDemo(HINSTANCE hInstance);
	~BoxDemo();

	bool Init();
	void OnResize();

	// Inherited via D3DApp
	virtual void UpdateScene(float dt) override;
	virtual void DrawScene() override;

	void OnMouseDown(WPARAM btnState, int x, int y);
	void OnMouseUp(WPARAM btnState, int x, int y);
	void OnMouseMove(WPARAM btnState, int x, int y);

private:
	void BuildGeometryBuffers();
	void BuildFX();
	void BuildVertexLayout();

private:
	ID3D11Buffer* mBoxVB;
	ID3D11Buffer* mBoxIB;

	ID3DX11Effect* mFX;
	ID3DX11EffectTechnique* mTech;
	ID3DX11EffectMatrixVariable* mfxWorldViewProj;

	ID3D11InputLayout* mInputLayout;

	DirectX::XMFLOAT4X4 mWorld;
	DirectX::XMFLOAT4X4 mView;
	DirectX::XMFLOAT4X4 mProj;

	float mTheta;
	float mPhi;
	float mRadius;

	POINT mLastMousePos;
};

