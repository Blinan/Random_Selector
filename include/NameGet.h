#pragma once
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "NameGet.h"
#include "define.h"

int NameGet(char char_name[MAX_NUM_NAME][MAX_NAMESISE], char* FileName_Namelist)
{
	errno_t err_fnamelist = 0;

	FILE* fpNameList = NULL;


	int NameTotalNum = 0;
	int i = 0;

	err_fnamelist = fopen_s(&fpNameList, FileName_Namelist, "r");

	if (err_fnamelist != 0)
	{
		printf("Can't open %s", FileName_Namelist);
		exit(EXIT_FAILURE);
	}

	while ((fgets(&char_name[i][0], MAX_NAMESISE, fpNameList) != NULL))
		i++;
	NameTotalNum = i;


	fclose(fpNameList);


	return NameTotalNum;
}