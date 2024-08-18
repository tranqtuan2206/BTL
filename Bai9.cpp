*#include <stdio.h>

void calculate(int* pa, int* pb, int* sum, int* difference, int* product, float* quotient) {
    *sum = *pa + *pb;
    *difference = *pa - *pb;
    *product = *pa * *pb;
    if (*pb != 0) {
        *quotient = (float)*pa / *pb;
    }
    else {
        printf("Loi chia cho 0!\n");
        *quotient = 0;
    }
}

int main() {
    int a, b;
    int sum, difference, product;
    float quotient;

    printf("Nhap hai so nguyen (a va b): ");
    scanf_s("%d %d", &a, &b);

    calculate(&a, &b, &sum, &difference, &product, &quotient);

    printf("Tong: %d\n", sum);
    printf("Hieu: %d\n", difference);
    printf("Tich: %d\n", product);
    printf("Thuong: %.2f\n", quotient);

    printf("Dia chi cua tong: %p\n", (void*)&sum);
    printf("Dia chi cua hieu: %p\n", (void*)&difference);
    printf("Dia chi cua tich: %p\n", (void*)&product);
    printf("Dia chi cua thuong: %p\n", (void*)&quotient);

    return 0;
}