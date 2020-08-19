#pragma once
#include "singleton.h"
class CSoundManager;
class CSound;
class SoundManager : public singleton<SoundManager>  
{
private:
	CSoundManager * Manager;
	map<string, CSound*> mSound;
public:
	SoundManager();
	~SoundManager();
	void AddSound(string key, wstring path);
	void Play(string key, bool loop);
	void Copy(string key);
	void Stop(string key);
};

#define SOUND SoundManager::GetInstance();

