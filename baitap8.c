#include <stdio.h>
int timUCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
	int num1, num2, num3;
	printf("Nhap so thu nhat: ");
	scanf("%d", &num1);
	printf("\nNhap so thu hai: ");
	scanf("%d", &num2);
	printf("\nNhap so thu ba: ");
	scanf("%d", &num3);
    int uclnHaiSoDau = timUCLN(num1, num2);
    int uclnBaSo = timUCLN(uclnHaiSoDau, num3);
    printf("\nUCLN cua %d, %d và %d là: %d\n", num1, num2, num3, uclnBaSo);
    return 0;
}

