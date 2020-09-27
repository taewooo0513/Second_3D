#include "DXUT.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

Scene * SceneManager::AddScene(string key, Scene * scene)
{
	if (!scene)
		return nullptr;
	if (mScene.find(key) != mScene.end())
		return nullptr;
	mScene[key] = scene;
	return scene;
}

void SceneManager::ChangeScene(string key)
{
	auto find = mScene.find(key);
	if (find == mScene.end())
	{
		return;
	}
	NextScene = find->second;
}

void SceneManager::Update()
{
	if (NextScene)
	{
		if (NowScene)
		{
			NowScene->Release();
		}
		OBJ->Release();

		NowScene = NextScene;
		NextScene = nullptr;
		NowScene->Init();
	}
	if (NowScene)
	{
		NowScene->Update();
	}
}

void SceneManager::Render()
{
	if (NowScene)
	{
		NowScene->Render();
	}
}

void SceneManager::UIRender()
{
	if (NowScene)
	{
		NowScene->UIRender();
	}
}

void SceneManager::Release()
{
	OBJ->Release();
	if (NowScene)
	{
		NowScene->Release();
	}
	for (auto iter : mScene)
	{
		SAFE_DELETE(iter.second);
	}
	mScene.clear();
}
