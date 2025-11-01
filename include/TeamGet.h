
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "define.h"

void TeamGet(char *FileName, int NameTotal, int FTeam[MAX_NUM_NAME])
{
	int i = 0;
	errno_t err_fnamelist = 0;
	FILE* fpNameList = NULL;
	err_fnamelist = fopen_s(&fpNameList, FileName, "r");


	if (err_fnamelist!= 0)
	{
		printf("Error: %d\n", err_fnamelist);
		exit(1);
	}
	while (fscanf_s(fpNameList, "%d", &FTeam[i]) == 1)
		i++;
	fclose(fpNameList);
}