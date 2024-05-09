#include <stdio.h>



void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			for (int j = 0; j < i; i++){
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
		}
	}
}


void bubbleSort(int arr[], int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}


void selectionSort(int arr[], int n) {
	for (int i = 0; i < size -1; i++) {
		minIndex = i;
		for(int j = i+1; j < size; j++) {
			if (arr[j] < arr[minIndex]) minIndex = j;
			if (minIndex != i) {
				int temp = arr[minIndex];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
			}
		}
	}
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);
    bubbleSort(arr, n);
    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
