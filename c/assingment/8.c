//using continue
#include <stdio.h>

int main() {
    int i;

    printf("Even numbers from 1 to 10, excluding 8:\n");

    for (i = 1; i <= 10; i++) {
        if (i == 8) {
            continue;
        }
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}


//using break

#include <stdio.h>

int main() {
    int i;

    printf("Even numbers from 1 to 10 except stopping at 8:\n");

    for (i = 1; i <= 10; i++) {
        if (i == 8) {
            break; 
        }
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}