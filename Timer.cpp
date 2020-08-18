#include "DXUT.h"
#include "Timer.h"

Timer::Timer(FLOAT Del)
	:m_Del(Del)
{
}

BOOL Timer::Update()
{
	m_Start += DTime;
	if (m_Start > m_Del)
	{
		m_Start = 0.f;
		return TRUE;
	}
	return FALSE;
}
