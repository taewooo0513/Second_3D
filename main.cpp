#include "DXUT.h"
#include "main.h"
#include <thread>

main::main()
{
}

main::~main()
{
}

void main::Init()
{
	thread t1([]() {
		IMAGE->AddMesh("t1", "./resource/47-obj/obj/Handgun_obj.obj"); 
	});
	thread t2([]() {
		IMAGE->AddMesh("t2", "./resource/72-rigged_hand_obj/Rigged Hand.obj");
	});
	t1.detach();

	t2.detach();

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
