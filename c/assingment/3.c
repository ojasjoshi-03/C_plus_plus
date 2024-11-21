#include <stdio.h>
#include <math.h> 

int main() {
    int a, b, c, d, e;
    int S, X, Y, Z;

    printf("Enter values for a, b, c, d, and e: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    S = a + b * c;
    printf("S = a + b * c = %d\n", S);

    X = a + b * c / d % 2;
    printf("X = a + b * c / d %% 2 = %d\n", X);

    Z = a + b * c - (d++) / e; 
    printf("Z = a + b * c - (d++) / e = %d\n", Z);

    Z = a % b + 5 * c / 3 * d;
    printf("Z = a %% b + 5 * c / 3 * d = %d\n", Z);

    Y = d * 2 / a - b;
    printf("Y = d * 2 / a - b = %d\n", Y);

    Z = (int)pow(a, b) + c % d - a - 3 * c; 
    printf("Z = a^b + c %% d - a - 3 * c = %d\n", Z);

    return 0;
}