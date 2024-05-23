#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left[], int leftSize, int mid[], int midSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0, n = 0;

    while (i < leftSize && j < rightSize && n < midSize) {
        if (left[i] <= right[j] && left[i] <= mid[n]) {
            arr[k] = left[i];
            i++;
        }
        else if (left[i] >= right[j] && left[i] >= mid[n]){
            arr[k] = right[j];
            j++;
        } else {
            arr[k] = mid[n];
            n++
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (i < leftSize) {
        arr[k] = mid[n];
        n++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform mergesort
void mergeSort(int arr[], int size) {
    if (size <= 1) return;

    int partSize = size / 3;
    int remainder = size % 3;

    int size1 = partSize + (remainder > 0 ? 1 : 0);
    int size2 = partSize + (remainder > 1 ? 1 : 0);
    int size3 = partSize;

   int left[size1], mid[size2], right[size3];

    // Divide the array into three thirds
    for (int i = 0; i < size1; i++) {
        left[i] = arr[i];
    }

    for (int i = size1; i < size2; i++) {
        right[i] = arr[i];
    }

    for (int i = size2; i < size3; i++) {
        right[i] = arr[i];
    }

    // Recursively sort the two halves
    mergeSort(left, size1);
    mergeSort(mid, size2);
    mergeSort(right, size3);

    // Merge the sorted halves
    merge(arr, left, size1, mid, size2, right, size3);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {9, 5, 2, 8, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}