#include <stdio.h>

size_t strlenn(char *str) {
    size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

void insertString(char text[], char str[], int position) {
    int textLength = (int)strlenn(text);
    int strLength = (int)strlenn(str);
    int newTextLength = textLength + strLength;

    if (position < 0 || position > textLength ) {
        printf("Invalid.\n");
        return;
    }
// || newTextLength >= sizeof(text
    // Shift characters to the right to make space for str
    for (int i = textLength - 1; i >= position; i--) {
        text[i + strLength] = text[i];
    }

    // Insert str into text at position
    for (int i = 0; i < strLength; i++) {
        text[position + i] = str[i];
    }
}

int main() {
    char text[20] = "The wrong son";
    char str[] = "per";
    int position = 10;

    insertString(text, str, position);

    printf("Modified text: %s\n", text);

    return 0;
}
