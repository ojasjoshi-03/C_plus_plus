#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;

    for (int i = 0; i < size; i++) {
        printf("Value at index %d: %d\n", i, *ptr);
        ptr++;
    }

    return 0;
}



