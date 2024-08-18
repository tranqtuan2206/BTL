#include <iostream>
#include <limits.h> 

struct Fraction {
    int numerator;   
    int denominator; 
};

float getFractionValue(const Fraction& f) {
    if (f.denominator == 0) {
        std::cerr << "Loi: Mau so phai khac 0!" << std::endl;
        return 0.0;
    }
    return static_cast<float>(f.numerator) / f.denominator;
}

Fraction findMaxFraction(const Fraction arr[], int size) {
    if (size <= 0) {
        std::cerr << "Mang rong!" << std::endl;
        return { 0, 1 };
    }

    Fraction maxFraction = arr[0];
    for (int i = 1; i < size; i++) {
        if (getFractionValue(arr[i]) > getFractionValue(maxFraction)) {
            maxFraction = arr[i];
        }
    }
    return maxFraction;
}

Fraction findMinFraction(const Fraction arr[], int size) {
    if (size <= 0) {
        std::cerr << "Mang rong!" << std::endl;
        return { 0, 1 }; 
    }

    Fraction minFraction = arr[0];
    for (int i = 1; i < size; i++) {
        if (getFractionValue(arr[i]) < getFractionValue(minFraction)) {
            minFraction = arr[i];
        }
    }
    return minFraction;
}
void deleteElement(Fraction arr[], int& size, int k) {
    if (k < 0 || k >= size) {
        std::cerr << "Vi tri xoa khong hop le." << std::endl;
        return;
    }

    for (int i = k; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
void insertElement(Fraction arr[], int& size, int k, const Fraction& x) {
    if (k < 0 || k > size || size >= 100) {
        std::cerr << "Vi tri them khong hop le hoac mang da day." << std::endl;
        return;
    }

    for (int i = size; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    size++;
}
int main() {
    Fraction arr[100];
    int size = 0;
    int choice, k;
    Fraction x;

    std::cout << "Nhap so luong phan so: ";
    std::cin >> size;
    if (size > 100) size = 100; 

    for (int i = 0; i < size; i++) {
        std::cout << "Nhap tu so va mau so cho phan so " << i + 1 << ": ";
        std::cin >> arr[i].numerator >> arr[i].denominator;
    }

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tim phan so lon nhat\n";
        std::cout << "2. Tim phan so nho nhat\n";
        std::cout << "3. Xoa phan tu tai vi tri k\n";
        std::cout << "4. Them phan tu x tai vi tri k\n";
        std::cout << "5. Thoat\n";
        std::cout << "Chon tu 1 den 5: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            Fraction maxFraction = findMaxFraction(arr, size);
            std::cout << "Phan so lon nhat: " << maxFraction.numerator << "/" << maxFraction.denominator << std::endl;
        }
        break;
        case 2:
        {
            Fraction minFraction = findMinFraction(arr, size);
            std::cout << "Phan so nho nhat: " << minFraction.numerator << "/" << minFraction.denominator << std::endl;
        }
        break;
        case 3:
            std::cout << "Nhap vi tri k: ";
            std::cin >> k;
            deleteElement(arr, size, k);
            std::cout << "Mang sau khi xoa phan tu: \n";
            for (int i = 0; i < size; i++) {
                std::cout << arr[i].numerator << "/" << arr[i].denominator << " ";
            }
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "Nhap vi tri k: ";
            std::cin >> k;
            std::cout << "Nhap tu so va mau so cho phan so x: ";
            std::cin >> x.numerator >> x.denominator;
            insertElement(arr, size, k, x);
            std::cout << "Mang sau khi them phan tu: \n";
            for (int i = 0; i < size; i++) {
                std::cout << arr[i].numerator << "/" << arr[i].denominator << " ";
            }
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Thoat chuong trinh.\n";
            break;
        default:
            std::cerr << "Lua chon khong hop le. Vui long chon lai." << std::endl;
            break;
        }
    } while (choice != 5);

    return 0;
}