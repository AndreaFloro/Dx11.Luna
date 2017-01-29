#pragma once

#include "d3dApp.h"
#include "d3dx11Effect.h"
#include "GeometryGenerator.h"
#include "MathHelper.h"
#include "LightHelper.h"
#include "Effects.h"
#include "Vertex.h"
#include "RenderStates.h"
#include "Waves.h"

enum RenderOptions
{
	Lighting = 0,
	Textures = 1,
	TexturesAndFog = 2
};

class TreeBillboardApp : public D3DApp
{
public:
	TreeBillboardApp(HINSTANCE hInstance);
	~TreeBillboardApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

	void OnMouseDown(WPARAM btnState, int x, int y);
	void OnMouseUp(WPARAM btnState, int x, int y);
	void OnMouseMove(WPARAM btnState, int x, int y);

private:
	float GetHillHeight(float x, float z)const;
	DirectX::XMFLOAT3 GetHillNormal(float x, float z)const;
	void BuildLandGeometryBuffers();
	void BuildWaveGeometryBuffers();
	void BuildCrateGeometryBuffers();
	void BuildTreeSpritesBuffer();
	void DrawTreeSprites(DirectX::CXMMATRIX viewProj);

private:
	ID3D11Buffer* mLandVB;
	ID3D11Buffer* mLandIB;

	ID3D11Buffer* mWavesVB;
	ID3D11Buffer* mWavesIB;

	ID3D11Buffer* mBoxVB;
	ID3D11Buffer* mBoxIB;

	ID3D11Buffer* mTreeSpritesVB;

	ID3D11ShaderResourceView* mGrassMapSRV;
	ID3D11ShaderResourceView* mWavesMapSRV;
	ID3D11ShaderResourceView* mBoxMapSRV;
	ID3D11ShaderResourceView* mTreeTextureMapArraySRV;

	Waves mWaves;

	DirectionalLight mDirLights[3];
	Material mLandMat;
	Material mWavesMat;
	Material mBoxMat;
	Material mTreeMat;

	DirectX::XMFLOAT4X4 mGrassTexTransform;
	DirectX::XMFLOAT4X4 mWaterTexTransform;
	DirectX::XMFLOAT4X4 mLandWorld;
	DirectX::XMFLOAT4X4 mWavesWorld;
	DirectX::XMFLOAT4X4 mBoxWorld;

	DirectX::XMFLOAT4X4 mView;
	DirectX::XMFLOAT4X4 mProj;

	UINT mLandIndexCount;

	static const UINT TreeCount = 16;

	bool mAlphaToCoverageOn;

	DirectX::XMFLOAT2 mWaterTexOffset;

	RenderOptions mRenderOptions;

	DirectX::XMFLOAT3 mEyePosW;

	float mTheta;
	float mPhi;
	float mRadius;

	POINT mLastMousePos;
};

