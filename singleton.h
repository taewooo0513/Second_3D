#pragma once

template <typename T>
class singleton
{
private:
	static T  * p;
public:
	singleton() {}
	~singleton() {}
	static T * GetInstance()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseInstance()
	{
		if (p)
			p = delete p;
		p = nullptr;
	}
};

template <typename T>
T * singleton<T>::p = nullptr;