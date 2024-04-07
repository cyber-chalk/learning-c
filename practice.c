#include <stdio.h>
size_t strlenn(const char *str) {
    size_t len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}
int num = 5;

int lenn2 (const char *str) {
    const char* ptr = str;
    int sum = 0;
    while (ptr < (str) + sum) {
        sum++;
        ptr++;
    }
    return sum;
}


void question_5(const char *str, char *result) {
    size_t lenn = strlenn(str);
    printf("%ld", lenn);
    char secondString[lenn];
    int n = 0;
    for (int i = lenn - 1; i >= 0; i--) {
        result[n] = str[i];
        n++;
        if (result[n] == '@' || result[n] == '$' || result[n] == '#')
            result[n] = ' ';
    }
    result[n] = '\0';
    printf("%s", result);
}

int main () {
    printf("%d", num);
    const char str[7] = "hello";
    int nums[5] = {1, 2, 3, 4, 5};
    printf("%d", lenn2(str));
    // printf("size %ld\n", sizeof(str) / sizeof(str[0]));
    // printf("%ld", strlenn(str));
    char str2[6];
    // printf("%ld \n", strlenn(str));
    // question_5(str, str2);
    return 0;
}