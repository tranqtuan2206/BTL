#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printCharacters(char* st) {
    while (*st) {
        printf("%c ", *st);
        st++;
    }
    printf("\n");
}

void convertToUpper(char* st) {
    while (*st) {
        *st = toupper((unsigned char)*st);
        st++;
    }
}

void capitalizeWords(char* st) {
    int newWord = 1; 
    while (*st) {
        if (isspace((unsigned char)*st)) {
            newWord = 1;
        }
        else if (newWord) {
            *st = toupper((unsigned char)*st);
            newWord = 0;
        }
        st++;
    }
}

int main() {
    char st[100];
    int choice;

    printf("Nhap chuoi: ");
    fgets(st, sizeof(st), stdin);

    size_t len = strlen(st);
    if (len > 0 && st[len - 1] == '\n') {
        st[len - 1] = '\0';
    }

    do {
        printf("\nMenu:\n");
        printf("1. Xuat gia tri tung ky tu\n");
        printf("2. Chuyen cac ky tu ve dang chu hoa\n");
        printf("3. Chuyen ky tu dau moi tu ve dang chu hoa\n");
        printf("4. Thoat\n");
        printf("Chon tu 1 den 4: ");
        scanf_s("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printCharacters(st);
            break;
        case 2:
            convertToUpper(st);
            printf("Chuoi sau khi chuyen ve chu hoa: %s\n", st);
            break;
        case 3:
            capitalizeWords(st);
            printf("Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: %s\n", st);
            break;
        case 4:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}