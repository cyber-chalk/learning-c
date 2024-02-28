#include <stdio.h>
#include <stdlib.h> // for q sort

int comp(const void* a, const void* b) {
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;
    return (arg1 > arg2) - (arg1 < arg2);
}


size_t strlenn (char *str) {
    size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

// Function to check if two strings are permutations of each other
int perm(char str1[], char str2[]) {

    int len1 = strlenn(str1);
    int len2 = strlenn(str2);

   
    if (len1 != len2) return 0;

    // used quick sort since its O(n*logn) and my bubble sort was O(n^2)
    qsort(str1, len1, sizeof(char), comp);
    qsort(str2, len2, sizeof(char), comp);

    // for(int j = 0; j < len1; j++) {
    //     printf("%c", str2[j]);
    // }
   

    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // char str1[100] = "hello";
    // char str2[100] = "olleh";
    
    char str1[100], str2[100];

    // Getting input from the user
    printf("input: ");
    scanf("%s", str1);
    printf("input second num: ");
    scanf("%s", str2);

    // perm(str1, str2);
    // Checking if the strings are permutations and printing the result
    if (perm(str1, str2) == 1) printf("Output: True\n"); 
        else printf("Output: False\n");

    return 0;
}
