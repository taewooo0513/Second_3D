#pragma once
#include "singleton.h"
#include "Scene.h"
class SceneManager : public singleton<SceneManager>
{
private:
	Scene * NowScene = nullptr, * NextScene = nullptr;
	map<string, Scene*>mScene;
public:
	SceneManager();
	~SceneManager();
	Scene * AddScene(string key , Scene* scene);
	void ChangeScene(string key);
	void Update();
	void Render();
	void UIRender();
	void Release();
};
#define SCENE SceneManager::GetInstance()

