#include <stdio.h>

int onePercent(double number1, double number2) {
    double percent = 0.01 * num1;
    double num3 = num1 - num2;
    if (num3 > 0) num3 *= -1;
    return num3 <= percent;
}

int binarySearch(int arr[], int low, int high, int x, int within1p) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((arr[mid] == x  && within1p == 0 ) || (within1p == 1 && onePercent(x, mid) == 1))
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    printf("not in array");
    return -1;
}

int main () {
    int x; double arr[8] =  {1.11, 2.31, 3.51, 4.71, 5.81, 6.91, 7.12, 8.14};
    printf("input double");
    scanf("%lf", &x);

    if (binarySearch(arr, 0, 8) >= 0) printf("found in array");

    return 0;
}