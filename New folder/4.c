#include <stdio.h>

int main() {
    int arr[100], size = 0, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Read Array\n");
        printf("2. Print Array\n");
        printf("3. Print Sorted Array (Selection and Bubble Sort)\n");
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
                    int selectionSorted[100], bubbleSorted[100];
                    for (int i = 0; i < size; i++) {
                        selectionSorted[i] = arr[i];
                        bubbleSorted[i] = arr[i];
                    }

                    for (int i = 0; i < size - 1; i++) {
                        int minIndex = i;
                        for (int j = i + 1; j < size; j++) {
                            if (selectionSorted[j] < selectionSorted[minIndex]) {
                                minIndex = j;
                            }
                        }
                        int temp = selectionSorted[i];
                        selectionSorted[i] = selectionSorted[minIndex];
                        selectionSorted[minIndex] = temp;
                    }

                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - 1 - i; j++) {
                            if (bubbleSorted[j] > bubbleSorted[j + 1]) {
                                int temp = bubbleSorted[j];
                                bubbleSorted[j] = bubbleSorted[j + 1];
                                bubbleSorted[j + 1] = temp;
                            }
                        }
                    }

                    printf("Array sorted using Selection Sort: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", selectionSorted[i]);
                    }
                    printf("\n");

                    printf("Array sorted using Bubble Sort: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", bubbleSorted[i]);
                    }
                    printf("\n");
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
