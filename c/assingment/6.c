#include <stdio.h>

int main() {
    int percentageGroup;
    float percentage;
    printf("Enter the percentage of the student: ");
    scanf("%f", &percentage);

    percentageGroup = (int)(percentage / 10);

    switch (percentageGroup) {
        case 10: 
        case 9: 
            printf("Grade: A\n");
            break;
        case 8: 
            printf("Grade: B\n");
            break;
        case 7: 
           printf("Grade: C\n");
            break;
        case 6:  
            printf("Grade: D\n");
            break;
        default: 
           printf("Grade: F\n");
    }

    return 0;
}
