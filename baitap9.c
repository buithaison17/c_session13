#include<stdio.h>
void nhapMang(int row, int col, int arr[row][col]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("\nNhap phan tu arr[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
}
void inMang(int row, int col, int arr[row][col]){
	printf("\nIn theo ma tran: \n\n");
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void inGocMang(int row, int col, int arr[row][col]){
	printf("\nIn phan tu o goc mang theo ma tran: \n\n");
	printf("%d ", arr[0][0]);
	printf("%d\n", arr[0][col-1]);
	printf("%d ", arr[row-1][0]);
	printf("%d\n\n", arr[row-1][col-1]);
}
void inDuongBien(int row, int col, int arr[row][col]){
	printf("\nIn phan tu theo duong bien theo ma tran: \n\n");
	for(int i = 0; i < col; i++){
		printf("%d ", arr[0][i]);
	}
	printf("\n");
	for(int i = 0; i < col; i++){
		printf("%d ", arr[row-1][i]);
	}
	printf("\n");
	for(int i = 0; i < row; i++){
		printf("%d ", arr[i][0]);
	}
	printf("\n");
	for(int i = 0; i < row; i++){
		printf("%d ", arr[row-1][i]);
	}
	printf("\n\n");
}
void inDuongCheo(int row, int col, int arr[row][col]){
	printf("\nIn phan tu duong cheo theo ma tran\n\n");
	for(int i = 0; i < row; i++){
		printf("%d ", arr[i][i]);
	}
	printf("\n");
	int j = row - 1;
	for(int i = 0; i < row; i++){
		printf("%d ", arr[i][j--]);
	}
	printf("\n\n");
}
void inSoNguyenTo(int row, int col, int arr[row][col]){
	int prime[row*col], index = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int count = 0;
			for(int k = 1; k <= arr[i][j]; k++){
				if(arr[i][j] % k == 0){
					count++;
				}
			}
			if(count == 2){
				prime[index++] = arr[i][j];
			}
		}
	}
	printf("\n");
	for(int i = 0; i < index; i++){
		printf("%d ", prime[i]);
	}
	printf("\n\n");
}
int main(){
	int arr[100][100], choice, row, col, check = 0;
	do{
		printf("1. Nhap gia tri cac phan tu\n");
		printf("2. In cac phan tu trong mang theo ma tran\n");
		printf("3. In phan tu o goc mang theo ma tran\n");
		printf("4. In phan tu nam tren duong bien theo ma tran\n");
		printf("5. In cac phan tu nam tren duong cheo chinh va duong cheo phu theo ma tran\n");
		printf("6. In cac phan tu la so nguyen to theo ma tran\n");
		printf("7. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nNhap so hang (toi da 100): ");
				scanf("%d", &row);
				printf("\nNhap so cot (toi da 100): ");
				scanf("%d", &col);
				if(row < 0 || col < 0 || row > 100 || col > 100){
					printf("\nNhap khong hop le\n\n");
				}
				else{
					check = 1;
					nhapMang(row, col, arr);
				}
				break;
			case 2:
				if(check == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					inMang(row, col, arr);
				}
				break;
			case 3:
				if(check == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					inGocMang(row, col, arr);
				}
				break;
			case 4:
				if(check == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					inDuongBien(row, col ,arr);
				}
				break;
			case 5:
				if(check == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else if(row != col){
					printf("\nKhong ton tai duong cheo chinh do so cot khac so hang\n\n");
				}
				else{
					inDuongCheo(row, col ,arr);
				}
				break;
			case 6:
				if(check == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					inSoNguyenTo(row, col, arr);
				}
				break;
			case 7:
				printf("\nThoat hoan tat\n\n");
				break;
			default:
				printf("\nNhap khong hop le\n\n");
				break;
		}
	}
	while(choice != 7);
}
