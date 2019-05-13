#include <stdio.h> 
#include <math.h> 
#include <conio.h>
#include <malloc.h>
void get_array(int* parr, int size) {
	for (int i = 0; i < size; i++)
		scanf_s("%d", (parr + i));
}
void print_array(int* parr, int size) {
	for (int i = 0; i < size; ++i)
		printf("%3d", *(parr + i));
	printf("\n");
}
int(*compare)(int*, int*);
int compare_UP_DOWN(int *pX,int *pY) {
	if (*pX == *pY) return 0;
	if (*pX < *pY) return 1;
	if (*pX > *pY) return 2;
	
}
int compare_ABSOLUTE_VALUE(int *pX, int *pY) {
	if (abs(*pX) < abs(*pY)) return 3;
}

void replace(int *pX, int *pY) {
	int temp;
	temp = *pX;
	*pX = *pY;
	*pY = temp;
}

int *sort_array(int *parr, int size, int algotitm_of_sorting) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (compare(parr + j, parr + j + 1) == algotitm_of_sorting) replace(parr + j, parr + j + 1);
		}
	}
	return parr;
}

int main() {
	int size;
	int *array;
	int aloritm_of_sorting;
	printf("size=");
	scanf_s("%d", &size);
	array = (int*)malloc(size * sizeof(int));
	printf("choose an algorithm of array sorting\n 1-DOWN\n 2-UP\n 3-ABSOLUTE_VALUE\n");
	scanf_s("%d", &aloritm_of_sorting);

	
	if ((aloritm_of_sorting == 1) || (aloritm_of_sorting == 2)) compare = compare_UP_DOWN;
	else
	{
		if (aloritm_of_sorting == 3) compare = compare_ABSOLUTE_VALUE;
		else
		{
			printf("error");
		
		}

	}
	printf("your array:");
	get_array(array, size);
	print_array(array,size);
	printf("sorted array");
	print_array(sort_array(array, size, aloritm_of_sorting), size);


	_getch();
	return 0;
}




