#include "DXUT.h"
#include "cImageManager.h"

cImageManager::cImageManager()
{
	Loader = new cMeshLoader;
}

cImageManager::~cImageManager()
{
	for (auto iter : image)
	{
		SAFE_DELETE(iter.second);
	}
	image.clear();
	SAFE_DELETE(Loader);
}

Texture * cImageManager::AddImage(const string key, const string path)
{
	auto find = image.find(key);
	if (find == image.end())
	{
		if (D3DXCreateTextureFromFileExA(g_Device, path.c_str(), -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
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

Mesh * cImageManager::AddMesh(const string key, const string path)
{
	auto find = mMesh.find(key);
	if (find != mMesh.end())
	{
		return find->second;
	}
	Mesh*mesh = new Mesh;
	Loader->ObjLoad(mesh, path);
	mMesh[key] = mesh;
	return mesh;
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
