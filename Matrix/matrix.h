#include <stdlib.h>
#include <stdio.h>

typedef struct {
	unsigned int RC;
	unsigned int CC;
	double *D;
} TMatrix;



void SortMatrix(TMatrix* M) {
	double MinVal, Val;
	for (int i = 0; i < (*M).RC * (*M).CC; i++) {
		for (int j = i+1; j < (*M).RC * (*M).CC; j++) {
			if ((*M).D[i] > (*M).D[j]) {
				Val = (*M).D[j];
				(*M).D[j] = (*M).D[i];
				(*M).D[i] = Val;
			}
		}
	}
}

TMatrix* CloneMatrix(TMatrix* M) {
	TMatrix* C;
	C = (TMatrix*)malloc(sizeof(TMatrix));
	(*C).RC = (*M).RC; (*C).CC = (*M).CC;
	(*C).D = (double*)malloc(sizeof(double) * (*C).RC * (*C).CC);

	for (int i = 0; i < (*M).RC * (*M).CC; i++) {
		(*C).D[i] = (*M).D[i];
	}
	return C;
}

void PrintMatrix(TMatrix* M) {
	for (int i = 0; i < (*M).RC; i++)
	{
		for (int j = 0; j < (*M).CC; j++)
		{
			printf("%f,", (*M).D[i * (*M).CC + j]);
		}
		printf("%\n");
	}
}