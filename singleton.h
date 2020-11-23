#pragma once
#include <mutex>

template <typename T>
class singleton
{
private:
	inline static T  * p;
	inline static mutex m;
public:
	singleton() {}
	~singleton() {}
	static T * GetInstance()
	{
		lock_guard lock(m);
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseInstance()
	{
		lock_guard lock(m);
		if (p)
			 delete p;
		p = nullptr;
	}
};