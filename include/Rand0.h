#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "Rand.h"
#include "define.h"


void Fprintf(int NameLuckyValue[MAX_NUM_NAME], int team[MAX_TEAM][MAX_NUM_NAME], int WishRandTeam, char* FprintName, int NameNum);
int Rand0(int LuckyValue[MAX_NUM_NAME], int NameTotalNum, char* FprintName, int Team[MAX_TEAM][MAX_NUM_NAME], int WishRandTeam)
{

	int LuckyNum = 0; //存储随机到的数

	int Change[MAX_NUM_NAME][2] = { 0 };

	int RandNum = 0;
	int Sum = 0;
	int Value[MAX_NUM_NAME] = { 0 };
	if (WishRandTeam != 9999)
	{
		printf("err:The team function is unavalible.");
		exit(1);
	}
	if (WishRandTeam == 9999)
	{

		for (int i = 0; i < NameTotalNum; i++)
			Sum += LuckyValue[i];
		for (int g = 0; g < NameTotalNum; g++)
			Value[g] = 0;

		for (int h = 0; h < NameTotalNum; h++)
		{
			Value[h] += LuckyValue[h];
		}
		for (int m = 0; m < NameTotalNum - 1; m++)
		{
			Value[m + 1] += Value[m];
		}



		{
			RandNum = rand() % Sum;
			for (int j = 0; j < NameTotalNum; j++)
			{

				if (Value[j] > RandNum)
				{
					if (Value[j] % 2 != 0)
					{
						for (int n = 0; n < NameTotalNum; n++)
						{
							LuckyValue[n] <<= 1;
						}
						LuckyValue[j] >>= 1;
						LuckyNum = j;
						break;
					}
					else if (LuckyValue[j] % 2 == 0)
					{
						LuckyValue[j] >>= 1;
						LuckyNum = j;
						break;
					}
				}

			}
		}
	}



	Fprintf(LuckyValue, Team, WishRandTeam, FprintName, NameTotalNum);

	return LuckyNum;


}

void Fprintf(int NameLuckyValue[MAX_NUM_NAME], int Team[MAX_TEAM][MAX_NUM_NAME], int WishRandTeam, char* FprintName, int NameNum)
{
	errno_t err = 0;
	FILE* fp = NULL;

	err = fopen_s(&fp, FprintName, "w+");

	if (err != 0)
	{

		printf("Can't open and write into %s", FprintName);
		//getchar();
		exit(EXIT_FAILURE);
	}

	else if (err == 0)
		if (WishRandTeam == 9999)
			for (int i = 0; i < NameNum; i++)
				fprintf(fp, "%d\n", NameLuckyValue[i]);
		else
		{

			for (int i = 0; i < NameNum; i++)
			{
				if (NameLuckyValue[i] != 0)
					fprintf(fp, "%d\n", Team[WishRandTeam][i]);
				else
				{
					fprintf(fp, "%d\n", NameLuckyValue[i]);
				}
			}
		}
	fclose(fp);
}