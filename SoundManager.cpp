#include "DXUT.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	Manager = new CSoundManager;
	Manager->Initialize(DXUTGetHWND(), 2);
}

SoundManager::~SoundManager()
{
	for (auto iter : mSound)
	{
		SAFE_DELETE(iter.second)
	}
	mSound.clear();
	SAFE_DELETE(Manager);
}

void SoundManager::AddSound(string key, wstring path)
{
	auto find = mSound.find(key);
	if (find != mSound.end())
	{
		return;

	}
	CSound * Sound;
	Manager->Create(&Sound, (LPWSTR)path.c_str());
	mSound[key] = Sound;
}

void SoundManager::Play(string key, bool loop)
{
	auto find = mSound.find(key);
	if (find == mSound.end())
	{
		return;
	}
	find->second->Play(0, loop);
}

void SoundManager::Copy(string key)
{
	auto find = mSound.find(key);
	if (find == mSound.end())
	{
		return;
	}
	LPDIRECTSOUNDBUFFER buff;
	Manager->GetDirectSound()->DuplicateSoundBuffer(find->second->GetBuffer(0), &buff);
	buff->SetCurrentPosition(0);
	buff->Play(0, 0, 0);
}

void SoundManager::Stop(string key)
{
	auto find = mSound.find(key);
	if (find == mSound.end())
	{
		return;
	}
	find->second->Stop();
}
