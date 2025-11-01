#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
int TeamKind(int FTeam[MAX_NUM_NAME], int KindNum[MAX_TEAM], int Team[MAX_TEAM][MAX_NUM_NAME] );// 计算队伍种类个数
int cmpfunc(const void* a, const void* b);
void HTeam(int FTeam[MAX_NUM_NAME], int Team[MAX_TEAM][MAX_NUM_NAME])
{
	int LuckyNum = 0;
	int TeamNum = 0;
	int KindNum[MAX_TEAM] = { 0 };
	TeamNum = TeamKind(FTeam, KindNum, Team);
	for (int i = 0; i < TeamNum; i++)
	{
		for (int j = 0; j < MAX_NUM_NAME; j++)
		{  
			if(FTeam[j] == KindNum[i])
				Team[i][j] = FTeam[j];  
		}
	}

}

int TeamKind(int FTeam[MAX_NUM_NAME], int KindNum[MAX_TEAM], int Team[MAX_TEAM][MAX_NUM_NAME]) 
{
	int Keep[MAX_NUM_NAME] = { 0 }; // 用于排序
	for (int i = 0; i < MAX_NUM_NAME; i++)
	{
		Keep[i] = FTeam[i];
	}
	qsort(Keep, MAX_NUM_NAME, sizeof(Keep[0]), cmpfunc); // 排序
	int TeamNum = 0;
	if (Keep[0] != 0)
		TeamNum++;
	if(Keep[0] == 0)
	{
		for (int i = 1; i < MAX_NUM_NAME; i++)
		{
			if (Keep[i] == 0)
				continue;

			if (Keep[i] != Keep[i - 1])
			{
				KindNum[TeamNum] = Keep[i];
				TeamNum++;
			}
		}
	}
	return TeamNum;

}

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
