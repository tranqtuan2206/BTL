#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printLocalMinima(int arr[], int size) {
    if (size < 3) {
        printf("Mang phai co it nhat 3 phan tu.\n");
        return;
    }

    printf("Cac so cuc tieu trong mang: ");
    for (int i = 1; i < size - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void deleteElement(int arr[], int* size, int k) {
    if (k < 0 || k >= *size) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }

    for (int i = k; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
void insertElement(int arr[], int* size, int k, int x) {
    if (k < 0 || k > *size || *size >= SIZE) {
        printf("Vi tri them khong hop le hoac mang da day.\n");
        return;
    }

    for (int i = *size; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*size)++;
}
void segregateEvenOdd(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }
        while (arr[right] % 2 != 0 && left < right) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}
int checkAlternatingEvenOdd(int arr[], int size) {
    if (size < 2) {
        return 1;
    }

    for (int i = 1; i < size; i++) {
        if ((arr[i] % 2 == arr[i - 1] % 2)) {
            return 0;
        }
    }
    return 1; 
}
int main() {
    int arr[SIZE] = { 1, 2, 4, 3, 7, 8, 6, 9, 10, 5 };
    int size = 10;
    int choice, k, x;

    do {
        printf("\nMenu:\n");
        printf("1. Xuat cac so cuc tieu\n");
        printf("2. Xoa phan tu tai vi tri k\n");
        printf("3. Them phan tu x tai vi tri k\n");
        printf("4. Chuyen so chan len dau, so le xuong cuoi\n");
        printf("5. Kiem tra mang co chua chan le xen ke\n");
        printf("6. Thoat\n");
        printf("Chon tu 1 den 6: ");
        scanf_s("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printLocalMinima(arr, size);
            break;
        case 2:
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            deleteElement(arr, &size, k);
            printf("Mang sau khi xoa phan tu: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            printf("Nhap gia tri x: ");
            scanf_s("%d", &x);
            insertElement(arr, &size, k, x);
            printf("Mang sau khi them phan tu: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 4:
            segregateEvenOdd(arr, size);
            printf("Mang sau khi chuyen so chan len dau, so le xuong cuoi: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 5:
            if (checkAlternatingEvenOdd(arr, size)) {
                printf("Mang chua so chan le xen ke.\n");
            }
            else {
                printf("Mang khong chua so chan le xen ke.\n");
            }
            break;
        case 6:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}