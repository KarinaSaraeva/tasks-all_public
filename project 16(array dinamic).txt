#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
#include <stdlib.h>

int i;
int *pArr;
void output_array(int *pArr, int N) {
	for (i = 0; i < N; ++i)
		printf("%3d", *(pArr + i));
	printf("\n");
}
void MAXIMUM(int *pArr, int N) {
	int *pmax;
	int  j;
	for (i = 0, j = 0, pmax = pArr; i < (N); ++i) {
		if (*(pmax + i - j) >= *pmax) {
			pmax += (i - j); j = i;
		}

	}
	printf("max_value=%d", *(pmax));
	printf("\n");
}
void MINIMUM(int *pArr, int N) {
	int *pmin;
	for (i = 0, pmin = pArr; i < (N ); ++i) {
		if (*(pmin) >= *(pArr + i)) {
			pmin = pArr + i;
		}

	}
	printf("min_value=%d", *(pmin));
	printf("\n");
}
double MEAN(int *pArr, int N) {
	int Sum = 0;
	for (i = 0; i < N; ++i)
		Sum += *(pArr + i);
	return  (double)Sum / N;
}
void standard_deviation(int *pArr, int N) {
	double sum_of_deviations = 0;
	for (i =0; i < N; ++i)
		sum_of_deviations += (*(pArr + i) - MEAN(pArr, N))*(*(pArr + i) - MEAN(pArr, N));
	printf("standard_deviation=%lf", sqrt((sum_of_deviations) / N));
}
int main() {
	int N;
	printf("Input elements count: ");
	scanf_s("%d", &N);
	printf("enter data\n");
	pArr = (int *)malloc(sizeof(int)*N);
	if (pArr == NULL)
	{
		printf("Can’t allocate memory!");
	}
	for (i = 0; i < N; i++)
		scanf_s("%d", (pArr + i));
	output_array(pArr, N);
	MAXIMUM(pArr, N);
	MINIMUM(pArr, N);
	MEAN(pArr, N);
	printf("mean_value=%lf\n", MEAN(pArr, N));
	standard_deviation(pArr, N);
	free(pArr);
	_getch();

	return 0;
}