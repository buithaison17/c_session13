#include<stdio.h>
int checkSort = 0;
void feature1(int n, int arr[]){
	for(int i = 0; i < n; i++){
		printf("\nNhap phan tu arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("\n");
}
void feature2(int n, int arr[]){
	for(int i = 0; i < n; i++){
		printf("\narr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");
}
void feature3(int index, int numbers, int n, int arr[]){
	for(int i = n; i > index; i--){
		arr[i] = arr[i-1];
	}
	arr[index] = numbers;
	printf("\nThem phan tu hoan tat\n");
}
void feature4(int index, int numbers, int n, int arr[]){
	arr[index] = numbers;
	printf("\nSua phan tu hoan tat hoan tat\n");
}
void feature5(int index, int n, int arr[]){
	for(int i = index; i < n-1; i++){
		arr[i] = arr[i+1];
	}
	printf("\nXoa phan tu hoan tat\n");
}
void feature6(int n, int arr[], char choice2){
	if(choice2 == 'a'){
		checkSort = 1;
		for(int i = 0; i < n; i++){
			int index  = i;
			for(int j = i+1; j < n; j++){
				if(arr[index] > arr[j]){
					index = j;
				}
			}
			if(index != i){
				int temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
			}
		}
		printf("\nSap xep hoan tat\n");
	}
	else if(choice2 == 'b'){
		checkSort = 2;
		for(int i = 0; i < n; i++){
			int index = i;
			for(int j = i+1; j < n; j++){
				if(arr[index] < arr[j]){
					index = j;
				}
			}
			if(index != i){
				int temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
			}
		}
		printf("\nSap xep hoan tat\n");
	}
	else{
		printf("\nNhap khong hop le\n");
	}
}
void feature7(int n, int arr[], char choice2){
	if(choice2 == 'a'){
		int index[n], j = 0, numbers;
		printf("\nNhap phan tu muon tim kiem: ");
		scanf("%d", &numbers);
		for(int i = 0; i < n; i++){
			if(numbers == arr[i]){
				index[j++] = i;
			}
		}
		if(j == 0){
			printf("\nPhan tu khong co trong mang\n\n");
		}
		else{
			printf("\nPhan tu %d co vi tri la: ", numbers);
			for(int i = 0; i < j; i++){
				printf("arr[%d] ", i);
			}
			printf("\n\n");
		}
	}
	if(choice2 == 'b'){
		if(checkSort == 0){
			printf("\nMang chua duoc sap xep\n\n");
		}
		else if(checkSort == 1){
			int start = 0, end = n - 1, numbers;
			printf("\nNhap so can tim: ");
			scanf("%d", &numbers);
			while(start <= end){
				int mid = (start + end) / 2;
				if(arr[mid] > numbers){
					end = mid - 1;
				}
				else if(arr[mid] < numbers){
					start = mid + 1;
				}
				else{
					printf("\nPhan tu %d co vi tri la: arr[%d]\n\n", numbers, mid);
					break;
				}
			}
		}
		else{
			int start = 0, end = n - 1, numbers;
			printf("\nNhap phan tu can tim kiem: ");
			scanf("%d", &numbers);
			while(start <= end){
				int mid = (start + end) / 2;
				if(arr[mid] > numbers){
					start = mid + 1;
				}
				else if(arr[mid] < numbers){
					end = mid - 1;
				}
				else{
					printf("\nPhan tu %d co vi tri la: arr[%d]", numbers, mid);
					break;
				}
			}
		}
	}
}
int main(){
	int arr[100], length, n, choice;
	do{
		printf("1. Nhap so phan tu va cac phan tu cua mang\n");
		printf("2. In ra cac phan tu trong mang\n");
		printf("3. Them mot phan tu vao mang\n");
		printf("4. Sua mot phan tu co trong mang\n");
		printf("5. Xoa mot phan tu\n");
		printf("6. Sap xep phan tu\n");
		printf("7. Tim kiem mot phan tu\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nNhap chieu dai cua mang (toi da 100): ");
				scanf("%d", &length);
				if(length < 1 || length > 100){
					printf("\nNhap khong hop le\n");
				}
				else{
					n = length;
					feature1(n, arr);
				}
				break;
			case 2:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					feature2(n, arr);
				}
				break;
			case 3:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else if(n >= length){
					printf("\nMang da day khong them them\n\n");
				}
				else{
					int index, numbers;
					printf("\nNhap vi tri muon them (0 --> %d): ", n);
					scanf("%d", &index);
					if(index < 0 || index > n){
						printf("\nVi tri nhap khong hop le\n\n");
					}
					else{
						printf("\nNhap phan tu muon them: ");
						scanf("%d", &numbers);
						feature3(index, numbers, n, arr);
						n++;
					}
				}
				break;
			case 4:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					int index, numbers;
					printf("\nNhap vi tri muon sua (0 --> %d): ", n-1);
					scanf("%d", &index);
					if(index < 0 || index > n-1){
						printf("\nVi tri sua khong hop le\n\n");
					}
					else{
						printf("\nNhap phan tu muon sua: ");
						scanf("%d", &numbers);
						feature4(index, numbers, n, arr);
					}
				}
				break;
			case 5:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					int index;
					printf("\nNhap vi tri muon xoa (0 --> %d): ", n-1);
					scanf("%d", &index);
					if(index < 0 || index > n-1){
						printf("\nVi tri xoa khong hop le\n\n");
					}
					else{
						feature5(index, n, arr);
						n--;
					}
				}
				break;
			case 6:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					char choice2;
					printf("\na. Tang dan\n");
					printf("\nb. Giam dan\n");
					printf("\nNhap chuc nang: ");
					getchar();
					scanf("%c", &choice2);
					feature6(n, arr, choice2);
				}
				break;
			case 7:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n\n");
				}
				else{
					char choice2;
					printf("\na. Tim kiem tuyen tinh\n");
					printf("\nb. Tim kiem nhi phan\n");
					printf("\nNhap chuc nang: ");
					getchar();
					scanf("%c", &choice2);
					feature7(n, arr, choice2);
				}
				break;
			case 8:
				printf("\nThoat hoan tat\n");
				break;
			default:
				printf("\nNhap khong hop le\n\n");
		}
	}
	while(choice != 8);
	return 0;
}
