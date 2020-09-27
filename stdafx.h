#pragma once
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

#pragma comment(lib,"dsound.lib")

static int m_speed = 1;

using namespace std;

#define VERTEXFVF D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_TEX1
#define DTime DXUTGetElapsedTime() * m_speed
#define g_Device DXUTGetD3D9Device()
#define g_VERTEXFVF D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_TEX1
#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
const int WINSIZEX =1920;
const int WINSIZEY =1080;
class Texture
{
public:
	Texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr), info(info)
	{
	}
	~Texture()
	{
	
	};
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
};

struct Material
{
	std::string mtlName;

	D3DMATERIAL9 material;
	Texture* DiffuseMap = nullptr;
	Texture* specularMap = nullptr;

	float fAlpha;
	float fIllum;
	float fNs;

	Material()
		:fAlpha(1.f), fIllum(0.f), fNs(0.f)
	{
		material.Power = 1;
	}
	~Material() { 
	
	}


};

struct Mesh
{
	bool bNoneDelete = false;

	LPD3DXMESH lpD3DXMesh;
	std::vector<Material*> vMaterial;

	Material * GetMaterial(int index)
	{
		return vMaterial[index];
	}

	Texture * GetDiffuseMap(int index)
	{
		return vMaterial[index]->DiffuseMap;
	}
	Texture* GetSpecularMap(int index)
	{
		return vMaterial[index]->specularMap;
	}
	Mesh() {}
	~Mesh()
	{
		for (auto iter : vMaterial)
			SAFE_DELETE(iter);

		vMaterial.clear();

		SAFE_RELEASE(lpD3DXMesh);
	}
};

struct VERTEX
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 normal;
	D3DXVECTOR2 tex;

	VERTEX(D3DXVECTOR3 _pos, D3DXVECTOR2 _tex, D3DXVECTOR3 _normal)
		:pos(_pos), tex(_tex), normal(_normal)
	{}
	~VERTEX() {  
	
	}
};

struct CacheEntry
{
	UINT index;
	CacheEntry* pNext;
};

#include "CamManager.h"
#include "Render2DManager.h"
#include "cRenderManager.h"
#include "cImageManager.h"
#include "cMeshLoader.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Timer.h"
#include "SDKsound.h"
#include "SoundManager.h"