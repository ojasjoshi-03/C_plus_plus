#include <stdio.h>

int main() {
    int arr[100], size = 0, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Read Array\n");
        printf("2. Print Array\n");
        printf("3. Print Addition of Array Elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if (size > 0) {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Array is empty.\n");
                }
                break;
            case 3:
                if (size > 0) {
                    int sum = 0;
                    for (int i = 0; i < size; i++) {
                        sum += arr[i];
                    }
                    printf("Sum of array elements: %d\n", sum);
                } else {
                    printf("Array is empty.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}




