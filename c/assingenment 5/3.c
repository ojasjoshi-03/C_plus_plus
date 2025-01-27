#include <stdio.h>

int searchElement(int *arr, int size, int key) {
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        if (*ptr == key) {
            return ptr - arr;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int index = searchElement(arr, size, key);

    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}

