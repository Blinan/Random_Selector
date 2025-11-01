#pragma once
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "define.h"

void NameLuckyValueGet(int NameNumGet[MAX_NUM_NAME], int NameNum, char* FileNameNamelist)
{


	errno_t err = 0;
	FILE* fp = NULL;
	int i = 0;

	err = fopen_s(&fp, FileNameNamelist, "r");

	if (err != 0)
	{
		printf("Can't open %s", FileNameNamelist);
		exit(EXIT_FAILURE);
	}

	while (fscanf_s(fp, "%d", &NameNumGet[i]) == 1)
		i++;
	fclose(fp);
}