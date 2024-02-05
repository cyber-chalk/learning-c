#include <stdio.h>
#include <math.h>

// I don't know how polynomials work

float calculate(float x) {
    float result = (3 * pow(x, 3)) - (5 * pow(x, 2)) + 6;;
    return result;
}

int main() {
    float x;
    printf("input x for: 3x^3 - 5x^2 + 6 \n");
    scanf("%f", &x);
    printf("%.2f \n", calculate(x));
    return 0;
}
