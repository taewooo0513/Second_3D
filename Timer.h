#pragma once
class Timer
{
private:
	FLOAT m_Start = 0;
	FLOAT m_Del = 0;
public:
	Timer(FLOAT Del);

	~Timer() {};
	BOOL Update();
};

