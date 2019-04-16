#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
#include <malloc.h>
int DET;
void printf_array(int *Parray, int string, int column) {
	for (int i = 0; i < string; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d\t", *(Parray + column * i + j));
		}
		printf("\n");
	}
}
void printf_array_double(double *Parray, int string, int column) {
	for (int i = 0; i < string; i++) {
		for (int j = 0; j < column; j++) {
			printf("%lf\t", *(Parray + column * i + j));
		}
		printf("\n");
	}
}
void put_in_array(int *Parray, int string, int column) {

	for (int i = 0; i < string; i++) {

		for (int j = 0; j < column; j++)
		{
			scanf_s("%d\t", (Parray + i * column + j));
		}

	}
	printf("\n");
}

void composition(int *Parray_1, int *Parray_2, int string, int column) {

	for (int i = 0; i < string; i++) {

		for (int k = 0; k < column; k++) {
			int c = 0;
			for (int j = 0; j < column; j++) {
				int a = *(Parray_1 + i * column + j);
				int b = *(Parray_2 + k + j * column);
				c += a * b;
			}
			printf("%d\t", c);
		}
		printf("\n");

	}
}

int determinant_po_minoram(int *Parray_1, int string, int column) {
	if (column != string) { printf("comilation error"); return 000; }

	if (column == 1)  return (*(Parray_1));
	//if (column == 1) { printf("%d", *Parray_1); return *(Parray_1); }
	int determinant = 0;
	for (int k = 0; k < column; k++) {
		int *Parray_dinamic = (int*)malloc((column - 1)*(column - 1) * sizeof(int));
		int g = 0;
		for (int i = 0; i < ((column)*(column)-column); i++) {
			if (i % column == k) g++;
			else {
				*(Parray_dinamic + i - g) = *(Parray_1 + i + column);
			}
		}

		int z = *(Parray_1 + k);
		determinant += pow(-1.0, k)*z*determinant_po_minoram(Parray_dinamic, string - 1, column - 1);
		free(Parray_dinamic);
	}
	return determinant;
}
int inverse_matrix(int *Parray_1, int string, int column) {
	double *Parray_inverse = (double*)malloc((column)*(column) * sizeof(int));
	if (DET == 0) { printf("complete error"); return 0; }
	for (int j = 0; j < string; j++) {
		for (int k = 0; k < column; k++) {
			int *Parray_minor = (int*)malloc((column - 1)*(column - 1) * sizeof(int));
			int g = 0;
			for (int i = 0; i < ((column)*(column)); i++) {
				if ((i % string == k) || ((i >= j * column) && (i < (j + 1)*column)))  g++;
				else
					*(Parray_minor + i - g) = *(Parray_1 + i);
			}
			int c = determinant_po_minoram(Parray_minor, string - 1, column - 1);
			
			*(Parray_inverse + k * column + j) = pow(-1.0, k + j)*c*pow(DET, -1);

		}
	
	}
	
	printf_array_double(Parray_inverse, string, column);
	FILE *file_1;


	if ((file_1 = fopen("res.txt", "w")) == NULL)
	{
		printf("error\n");
		return 0;
	}
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fprintf(file_1, "%lf\t", *(Parray_inverse + i * column + j));

		}

		fprintf(file_1, "\n");
	}
	fclose(file_1);
}

int main() {
	int string;
	int column;
	printf("use matrix from file?\n answer=");
	int answer;
	scanf_s("%d", &answer);
	int *array_1;
	if (answer == 1) {
		string = 3;
		column = 3;
		int i, j, array[3][3];


		FILE *file;


		if ((file = fopen("text.txt", "r")) == NULL)
		{
			printf("error\n");
			return 0;
		}
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				fscanf(file, "%d", &array[i][j]);
			}
		}
		array_1 = &array[0][0];
		fclose(file);
		printf("array 1 :");
		printf_array(array_1, string, column);
	}
	else {
		printf("string=");
		scanf_s("%d", &string);
		printf("column=");
		scanf_s("%d", &column);
		array_1 = (int*)malloc(column*string * sizeof(int*));
		put_in_array(array_1, string, column);
		printf("array:");

		printf_array(array_1, string, column);
	}
	DET = determinant_po_minoram(array_1, string, column);
	printf("DETERMINANT=%d\n", DET);
	/*printf("choose:\n 1-iverse matrix_1\n 2-matrix composition\n");
		int answer;
		scanf("%d", &answer);*/
	printf("inverse matrix:\n");
	
	inverse_matrix(array_1, string, column);
	printf("put in array 2 :\n");
	int *array_2 = (int*)malloc(column*string * sizeof(int*));
	put_in_array(array_2, string, column);
	printf("array 2 :\n");
	printf_array((int*)array_2, string, column);
	printf("matrix composition :\n");
	composition((int*)array_1, (int*)array_2, string, column);
	_getch();

	return 0;
}