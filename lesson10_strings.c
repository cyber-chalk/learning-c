#include <stdio.h>
typedef enum { false, true } bool;

void combine(char str1[], char str2[], char str3[]) {
    for(int i = 0; i < 5; i++) str3[i] = str1[i];
     for(int j = 0; j < 6; j++) str3[j + 5] = str2[j];
}



size_t strlenn (char *str) {
    size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

int count (char str[]) {
	size_t len = strlenn(str);
	int prevC = 1;
	int wordC = 0;
	for(int i = 0; i < len + 1; i++) {
		if ((str[i] >= 65 && str[i] <= 90 ) || (str[i] >= 97 && str[i] <= 122) && (str[i] != '\0')) {
			printf("%c	", str[i]);
			prevC = 0;
		} else {
			if (prevC == 0) wordC++;
			prevC = 1;
		}
	
	}
	return wordC;
}

bool compare (char str1[], char str2[]) {
    int size1 = strlenn(str1);
    int size2 = strlenn(str2);
    if (size1 != size2) return false;

     for (int i = 0; i < size1; i++) {
        if (str1[i] != str2[i]) {
            return true;
        }
    }
    return false;
}

int main () {
    char str1[6] = "hello";
    char str2[6] = "world";
    char str3[11];
    combine(str1, str2, str3);
	char mixedString[12] = "abc%abc+abc";
   // printf("%s", str3);
	printf("%d", count(mixedString));
   // printf("%d", compare(str1, str2));
    return 0;
}