#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void nhapChuoi(char **str) {
    *str = (char *)malloc(100 * sizeof(char));
    printf("Nhap chuoi: ");
    fgets(*str, 100, stdin);
    (*str)[strcspn(*str, "\n")] = 0;
}

void inChuoi(char *str) {
    printf("Chuoi: %s\n", str);
}

int demSoLuongChuCai(char *str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            count++;
        }
        str++;
    }
    return count;
}

int demSoLuongChuSo(char *str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}

int demSoLuongKyTuDacBiet(char *str) {
    int count = 0;
    while (*str) {
        if (!((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                if (str != NULL) {
                    inChuoi(str);
                } else {
                    printf("Vui long nhap chuoi truoc.\n");
                }
                break;
            case 3:
                if (str != NULL) {
                    printf("So luong chu cai: %d\n", demSoLuongChuCai(str));
                } else {
                    printf("Vui long nhap chuoi truoc.\n");
                }
                break;
            case 4:
                if (str != NULL) {
                    printf("So luong chu so: %d\n", demSoLuongChuSo(str));
                } else {
                    printf("Vui long nhap chuoi truoc.\n");
                }
                break;
            case 5:
                if (str != NULL) {
                    printf("So luong ky tu dac biet: %d\n", demSoLuongKyTuDacBiet(str));
                } else {
                    printf("Vui long nhap chuoi truoc.\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                free(str);
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);

    return 0;
}