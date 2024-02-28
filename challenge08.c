#include <stdio.h>

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


// apparently this is the more efficient version of bubble sort
// however its still O(N^2)

int main() {
	int num[9] = {1, 5, 6, 9, 4, 3, 8, 2, 0};
	// printf("write numbers\n");
	
	// for(int i = 0; i < 10 ; i++) {
	// 	scanf("%d", &num[i]);
	// }
    int size = sizeof(num) / sizeof(num[0]);
	// bubble sort
	
	bubbleSort(num, size);

    for (int n = 0; n < size; n++) printf("%d,", num[n]);

	return 0;
}