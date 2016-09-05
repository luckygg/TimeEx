#pragma once

#include "stdafx.h"

class CTimeEx
{
public:
	CTimeEx(void) {}
	~CTimeEx(void) {}

private :
	LARGE_INTEGER m_Start;
	LARGE_INTEGER m_Stop;
	LARGE_INTEGER m_Freq;
	double Time;

public :
	void Start() { QueryPerformanceFrequency(&m_Freq); QueryPerformanceCounter(&m_Start); }
	void Stop()  { QueryPerformanceCounter(&m_Stop);}
	double GetTimeMs() { return (double)(m_Stop.QuadPart - m_Start.QuadPart)/m_Freq.QuadPart*1000; }
};

