#include<stdio.h>
void matrix(int row, int col, int arr[row][col]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("\nNhap phan tu arr[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}
void printMatrix(int col, int row, int arr[row][col]){
	printf("\nMang in theo ma tran la: \n\n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%d	", arr[i][j]);
		}
		printf("\n\n");
	}
}
int main(){
	int row, col;
	printf("Nhap so hang: ");
	scanf("%d", &row);
	printf("\nNhap so cot: ");
	scanf("%d", &col);
	int arr[row][col];
	matrix(row, col, arr);
	printMatrix(row, col ,arr);
	return 0;
}
