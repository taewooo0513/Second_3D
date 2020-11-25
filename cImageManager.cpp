#include "DXUT.h"
#include "cImageManager.h"
#include <mutex>
#include <shared_mutex>

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

shared_mutex imageMutex;
Texture * cImageManager::AddImage(const string key, const string path)
{
	shared_lock readLock(imageMutex);
	auto find = image.find(key);
	if (find == image.end())
	{
		readLock.unlock();
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;
		if (D3DXCreateTextureFromFileExA(g_Device, path.c_str(), -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			Texture * text = new Texture(texturePtr, info);
			lock_guard writeLock(imageMutex);
			image[key] = text;
			return text;
		}
		return nullptr;
	}
	return find->second;
}

Texture * cImageManager::FindImage(const string key)
{
	shared_lock readLock(imageMutex);
	auto find = image.find(key);
	if (find == image.end())
	{
		return nullptr;
	}
	return find->second;
}

shared_mutex meshMutex;
Mesh * cImageManager::AddMesh(const string key, const string path)
{
	shared_lock readLock(meshMutex);
	auto find = mMesh.find(key);
	if (find != mMesh.end())
	{
		return find->second;
	}
	readLock.unlock();

	Mesh*mesh = new Mesh;
	cMeshLoader loader;
	loader.ObjLoad(mesh, path);
	lock_guard lock(meshMutex);
	mMesh[key] = mesh;
 	return mMesh[key];

}

Mesh * cImageManager::FindMesh(const string key)
{
	shared_lock readLock(meshMutex);
	auto find = mMesh.find(key);
	if (find == mMesh.end())
	{
		return nullptr;
	}
	return find->second;
}
