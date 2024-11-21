#include <stdio.h>

int main() {
    int a, b, result;
    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);
    result = (a > b) ? a : b;
    printf("The larger number between %d and %d is %d\n", a, b, result);
    return 0;
}
