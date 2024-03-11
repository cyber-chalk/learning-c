#include <stdio.h>


size_t strlenn (char *str) {
    size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

int findString(char source[], char search[]) { 
    int strLen = (int)strlenn(source);
    int str2Len = (int)strlenn(search);
    for(int i = 0; i < strLen; i++) {
        int found = 0;
        for (int n = 0; n < str2Len; n++) {
            if (source[i + n] != search[n]) {
                found = 1;
                break;
            };
        if (found == 0) return i;
       }
    }
    return 2;
}


void substring(char source[], int start, int count) {
    char result[count + 1];
    for(int i = start; i < count + start; i++) {
        result[i - start] = source[i];
        // printf("%d", i);
    }
     result[count] = '\0';
     printf("%s", result);
}




int main () {
    char str[26] = "abcdefghijklmnipqrstuvwxyz";
    char str2[5] = "lmnop";

    // substring(str, 5, 5);
    printf("%d", findString(str, str2));
    return 0;
}