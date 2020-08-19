#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::Update()
{
	for (auto iter : listObj)
	{
		iter->Update();
	}
}

void ObjectManager::Render()
{
	for (auto iter : listObj)
	{
		iter->Render();
	}
}

void ObjectManager::UIRender()
{
	for (auto iter : listObj)
	{
		iter->Render();
	}
}

void ObjectManager::Release()
{
	for (auto iter : listObj)
	{
		SAFE_DELETE(iter);
	}
	listObj.clear();
}

Object * ObjectManager::AddObj(Object * obj)
{
	if (obj)
	{
		listObj.push_back(obj);
	}
	return obj;
}
