#include <stdio.h>

size_t strlenn (char *str) {
    size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

void copyString(char *to, char *from) {
	// printf("%c", to[0]);
	size_t length = strlenn(from);
	
	if(*to != '\0') *to = to[length];
	*to = '\0';
	for (int i = 0; i < length; i++) {
		to[i] = from[i];
	}
}




int main () {
	char str1[10] = "hello";
	char str2[10] = "world";
	copyString(str2, str1);
	printf("%s %s", str1, str2);
	return 0;
}
