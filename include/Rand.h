#pragma once
#include <stdio.h>
#include <windows.h>
#include "define.h"
int Rand(int NameNum)
{
	int LuckyNameNum = 0;
	LuckyNameNum = rand() % NameNum;
	return LuckyNameNum;
}

