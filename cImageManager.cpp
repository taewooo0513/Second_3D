#include "DXUT.h"
#include "cImageManager.h"
#include <mutex>

cImageManager::cImageManager()
{
}

cImageManager::~cImageManager()
{
	for (auto iter : image)
	{
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	image.clear();
	for (auto iter : mMesh)
	{
		SAFE_DELETE(iter.second);
	}
	mMesh.clear();
}

mutex imageMutex;
Texture * cImageManager::AddImage(const string key, const string path)
{
	auto find = image.find(key);
	if (find == image.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;
		if (D3DXCreateTextureFromFileExA(g_Device, path.c_str(), -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			lock_guard<mutex> lock(imageMutex);
			Texture * text = new Texture(texturePtr, info);
			image[key] = text;
			return text;
		}
		return nullptr;
	}
	return find->second;
}

Texture * cImageManager::FindImage(const string key)
{
	auto find = image.find(key);
	if (find== image.end())
	{
		return nullptr;
	}
	return find->second;
}

mutex meshMutex;
Mesh * cImageManager::AddMesh(const string key, const string path)
{
	auto find = mMesh.find(key);
	if (find != mMesh.end())
	{
		return find->second;
	}
	Mesh*mesh = new Mesh;
	cMeshLoader loader;
	loader.ObjLoad(mesh, path);
	lock_guard<mutex> lock(meshMutex);
	mMesh[key] = mesh;
 	return mMesh[key];

}

Mesh * cImageManager::FindMesh(const string key)
{
	auto find = mMesh.find(key);
	if (find == mMesh.end())
	{
		return nullptr;
	}
	return find->second;
}
