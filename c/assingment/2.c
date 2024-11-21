#include <stdio.h>

int main() {
    float num1, num2, num3, num4, num5, average;

  
    printf("Enter five numbers: ");
    scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);

    
    average = (num1 + num2 + num3 + num4 + num5) / 5;

    
    printf("The average of the five numbers is: %.2f\n", average);

    return 0;
}