#include <stdio.h>
#include "lesson17_preprocessor.h"

int main()
{
    int result_add = add(5, 3);
    printf("5 + 3 = %d\n", result_add);

    int result_subtract = subtract(8, 4);
    printf("8 - 4 = %d\n", result_subtract);

    int result_multiply = multiply(2, 6);
    printf("2 * 6 = %d\n", result_multiply);

    int result_divide = divide(10, 2);
    printf("10 / 2 = %d\n", result_divide);

    return 0;
}