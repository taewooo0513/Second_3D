#include "DXUT.h"
#include "main.h"
#include "ExScene.h"
main::main()
{
}

main::~main()
{
}

void main::Init()
{
	IMAGE->AddImage("SEX","./resource/Object001CompleteMap.png");
	IMAGE->AddMesh("c","./resource/MAN.obj");
	SCENE->AddScene("EX",new ExScene);
	SCENE->ChangeScene("EX");
}

void main::Update()
{
	SCENE->Update();
	OBJ->Update();
}

void main::Render()
{
	
	SCENE->Render();
	OBJ->Render();
	RENDER2D->Begin();
	SCENE->UIRender();
	OBJ->UIRender();
	RENDER2D->End();
}

void main::Release()
{
	cImageManager::ReleaseInstance();
	cMeshLoader::ReleaseInstance();
	SoundManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	CamManager::ReleaseInstance();
	cRenderManager::ReleaseInstance();
	Render2DManager::ReleaseInstance();
}

void main::ResetDevice()
{
	RENDER2D->ResetDevice();
}

void main::LostDevice()
{
	RENDER2D->LostDevice();
}
