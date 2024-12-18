#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int));
    printf("Nhap %d phan tu:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Mang sau khi dao nguoc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepTang(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep tang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepGiam(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void timKiemPhanTu(int *arr, int n) {
    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d tim thay o vi tri %d\n", x, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Phan tu %d khong co trong mang\n", x);
    }
}

int main() {
    int *arr = NULL;
    int n, choice, sortChoice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                if (arr != NULL) {
                    inSoChan(arr, n);
                } else {
                    printf("Vui long nhap mang truoc.\n");
                }
                break;
            case 3:
                if (arr != NULL) {
                    inSoNguyenTo(arr, n);
                } else {
                    printf("Vui long nhap mang truoc.\n");
                }
                break;
            case 4:
                if (arr != NULL) {
                    daoNguocMang(arr, n);
                } else {
                    printf("Vui long nhap mang truoc.\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    printf("MENU CON\n");
                    printf("1. Sap xep tang dan\n");
                    printf("2. Sap xep giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &sortChoice);
                    switch (sortChoice) {
                        case 1:
                            sapXepTang(arr, n);
                            break;
                        case 2:
                            sapXepGiam(arr, n);
                            break;
                        default:
                            printf("Lua chon khong hop le.\n");
                    }
                } else {
                    printf("Vui long nhap mang truoc.\n");
                }
                break;
            case 6:
                if (arr != NULL) {
                    timKiemPhanTu(arr, n);
                } else {
                    printf("Vui long nhap mang truoc.\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                free(arr);
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}