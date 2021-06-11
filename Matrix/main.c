  
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#pragma warning(disable : 4996)

int main()
{
	TMatrix *M, *S;
	FILE* f;
	int n, RC, CC;
	f = fopen("input.txt", "rt");
	n = fscanf(f, "%d, %d\n", &RC, &CC);
	M = (TMatrix*)malloc(sizeof(TMatrix));

	int i, j, di, dj, k;

	(*M).RC = RC;
	(*M).CC = CC;
	(*M).D = (double*)malloc(sizeof(double) * RC * CC);

	for (i = 0; i < (*M).RC; i++)
	{
		for (j = 0; j < (*M).CC; j++)
		{
			fscanf(f, "%lf,", &((*M).D[i * (*M).CC + j]));
		}
	}


	fclose(f);

	S=CloneMatrix(M);
	SortMatrix(S);

	i = 0; j = 0; dj = 1; di = -1; k = 0;
	while( 1==1 )
	{
		(*M).D[i * (*M).CC + j] =  (*S).D[k];
		k++;

		if (((i + 1) == (*M).RC) && ((j + 1) == (*M).CC)) { break; }

		i = i + di;
		j = j + dj;

		if (i == (*M).RC) {
			j = j + 2;
			i = i - 1;
			di = -1;
			dj = 1;
		}

		if (j == (*M).CC) {
			i = i + 2;
			j = j - 1;
			dj = -1;
			di = 1;
		}


		if (j == -1) {
			j = 0;
			dj = 1;
			di = -1;
		}

		if (i == -1) {
			i = 0;
			di = 1;
			dj = -1;
		}
	}

	PrintMatrix(M);

}
