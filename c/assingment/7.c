// Print 10 Numbers Using for, while, and do-while Loops
#include <stdio.h>

int main() {
    int i;

    printf("Using for loop:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Using while loop:\n");
    i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    printf("Using do-while loop:\n");
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);
    printf("\n");

    return 0;
}


//Menu-Driven Program


#include <stdio.h>

int main() {
    int choice, i;
    float sum = 0, avg;

    printf("Menu:\n");
    printf("1. Print addition of 10 numbers using for loop\n");
    printf("2. Print average of first 10 numbers using while loop\n");
    printf("3. Print square of first 10 numbers using do-while loop\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sum = 0;
            for (i = 1; i <= 10; i++) {
                sum += i;
            }
            printf("The sum of the first 10 numbers is: %.0f\n", sum);
            break;

        case 2:
            sum = 0;
            i = 1;
            while (i <= 10) {
                sum += i;
                i++;
            }
            avg = sum / 10;
            printf("The average of the first 10 numbers is: %.2f\n", avg);
            break;

        case 3:
            i = 1;
            printf("The squares of the first 10 numbers are:\n");
            do {
                printf("%d ", i * i);
                i++;
            } while (i <= 10);
            printf("\n");
            break;

        default:
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
    }

    return 0;
}