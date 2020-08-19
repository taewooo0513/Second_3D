#pragma once
#include "singleton.h"
#include "Object.h"
class ObjectManager : public singleton<ObjectManager>
{
private:
	list<Object*> listObj;
public:
	ObjectManager();
	~ObjectManager();
	void Update();
	void Render();
	void UIRender();
	void Release();
	Object* AddObj(Object * obj);

};

#define OBJ ObjectManager::GetInstance()