#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);

    *arr = (int *)malloc(*n * sizeof(int));

    if (*arr == NULL) {
        printf("Loi cap phat bo nho\n");
        exit(1);
    }

    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", (*arr) + i);
    }
}

void hienThiMang(int *arr, int n) {
    if (n == 0) {
        printf("Mang chua co phan tu nao.\n");
        return;
    }

    printf("Các phan tu trong mang la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int tinhDoDaiMang(int *arr) {
    return sizeof(arr) / sizeof(arr[0]);
}

int tinhTongMang(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += *(arr + i);
    }
    return tong;
}

int phanTuLonNhat(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong. Khong the tim phan tu lon nhat.\n");
        return -1;
    }

    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("Do dai mang la: %d\n", n);
                break;
            case 4:
                printf("Tong cac phan tu trong mang la: %d\n", tinhTongMang(arr, n));
                break;
            case 5:
                {
                    int max = phanTuLonNhat(arr, n);
                    if (max != -1) {
                        printf("Phan tu lon nhat trong mang la: %d\n", max);
                    }
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                free(arr);
                break;
            default:
                printf("Chuc nang khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}