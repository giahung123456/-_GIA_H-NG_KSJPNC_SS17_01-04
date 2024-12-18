#include <stdio.h>
#include <string.h>

void nhapChuoi(char *str) {
    printf("Nhap chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
}

void inChuoiDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int demSoLuongTu(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void soSanhChuoi(char *str1) {
    char str2[100];
    printf("Nhap chuoi so sanh: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    if (strlen(str2) < strlen(str1)) {
        printf("Chuoi so sanh ngan hon chuoi ban dau.\n");
    } else if (strlen(str2) > strlen(str1)) {
        printf("Chuoi so sanh dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaTatCaChu(char *str) {
    char *temp = str;
    while (*temp) {
        if (*temp >= 'a' && *temp <= 'z') {
            *temp = *temp - ('a' - 'A');
        }
        temp++;
    }
    printf("Chuoi in hoa: %s\n", str);
}

void themChuoi(char *str1) {
    char str2[100];
    printf("Nhap chuoi can them: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    strcat(str1, str2);
    printf("Chuoi sau khi them: %s\n", str1);
}

int main() {
    char str[100];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(str);
                break;
            case 2:
                inChuoiDaoNguoc(str);
                break;
            case 3:
                {
                    char tempStr[100];
                    strcpy(tempStr, str);
                    printf("So luong tu trong chuoi: %d\n", demSoLuongTu(tempStr));
                }
                break;
            case 4:
                soSanhChuoi(str);
                break;
            case 5:
                inHoaTatCaChu(str);
                break;
            case 6:
                themChuoi(str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Chuc nang khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}