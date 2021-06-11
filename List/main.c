#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void PrintDouble(TSinglLinkElement * CurrentElement) {
	while (CurrentElement != NULL)
	{
		printf("%f\n", *((double*)((*CurrentElement).data)));
		CurrentElement = (*CurrentElement).next;
	}
}

short int CheckDouble(void* D1, void* D2) {
	if ((*((double*)D1)) > (*((double*)D2))) { return 1; }
	if ((*((double*)D1)) < (*((double*)D2))) { return -1; }
	return 0;
}

int main(int argc, char **argv) {
	TSinglLinkElement *First, *Current, *Prev;
	double	*data, val;

	data = (double*)malloc(sizeof(double));
	*data = 1;
	First = InsertSinglLinkElement(NULL, data);

	data = (double*)malloc(sizeof(double));
	*data = 2;
	Current = InsertSinglLinkElement(First, data);

	data = (double*)malloc(sizeof(double));
	*data = 3;
	Current = InsertSinglLinkElement(Current, data);

	data = (double*)malloc(sizeof(double));
	*data = 4;
	Current = InsertSinglLinkElement(Current, data);

	PrintDouble(First);

	val = 2;
	Current = SearchSinglLinkElementData(First, &val, CheckDouble);

	Prev = GetPrevSinglLinkElement(First, Current);
	DeleteNextSinglLinkElement(Prev);
	PrintDouble(First);

	return 1;
}