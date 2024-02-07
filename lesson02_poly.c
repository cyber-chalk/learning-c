#include <stdio.h>
#include <math.h>


float calculate(float x) {
    float result = (3 * pow(x, 3)) - (5 * pow(x, 2)) + 6;;
    return result;
}

float temp (int f) {
    float c = (f -32) / 1.8;
    // printf("%.2f", c);
    return c;
}

int main() {
    // float x;
    // printf("input x for: 3x^3 - 5x^2 + 6 \n");
    // scanf("%f", &x);
    // printf("%.2f \n", calculate(x));
    // double result = (3.31e-8 * 2.01e-7) * (7.16e-6 * 2.01e-8);

    // printf("Result: %e\n", result);
    // int x = 44;
    // printf("base 8: %o \n", x);
    // printf("celcius: %.2f", temp(45));


    return 0;
}
