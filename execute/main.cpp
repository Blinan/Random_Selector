#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "NameGet.h" 
#include "Rand.h"
#include "define.h"
#include "NameNumGet.h"
#include "Rand0.h"
#include "TeamGet.h"
#include "Team.h"

int main(void)
{
	int RandLuckyNum = 0;
	int NameTotalNum = 0;
	int RandLuckyNum0 = 0;
	int circul = 1;        //传参
	int WishRandTeam = 9999;  //传参,如果为9999则不随机团队
	int Seed = 0;         //传参

	char File_1[] = "Name.txt";
	char File_2[] = "LuckyValue.csv";
	char File_3[] = "YourTeam.txt";

	char NameList[MAX_NUM_NAME][MAX_NAMESISE] = { " 0 " };
	int NameLuckyValue[MAX_NUM_NAME] = { 0 };
	int FTeam[MAX_NUM_NAME] = { 0 };
	int Team[MAX_TEAM][MAX_NUM_NAME] = { 0 };

	srand((unsigned int)time(NULL) + Seed);

	NameTotalNum =  NameGet(NameList ,File_1); //读取人数
	RandLuckyNum0 = Rand(NameTotalNum );     //库随机输出随机
	NameLuckyValueGet(NameLuckyValue, NameTotalNum ,File_2);  
	TeamGet(File_3, NameTotalNum, FTeam); //读取团队
	HTeam(FTeam, Team);
	

	for(int i = 0; i < 10000;i++)
	{
		Sleep(2);
			RandLuckyNum = Rand0( NameLuckyValue, NameTotalNum, File_2, Team, WishRandTeam);  //随机算法输出随机，Rand0函数不能高频调用
			RandLuckyNum0 = rand() % NameTotalNum;     //库随机输出随机
		printf("%d\n", RandLuckyNum);
	}

    getchar();

	return 0;
}