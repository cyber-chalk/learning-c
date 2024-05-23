#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char sentence[MAX_LEN];
    char word[MAX_LEN];

    printf("enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // printf("%s", sentence);

    printf("Enter word: ");
    scanf("%s", word);

    // Linear search to find the word in the sentence
    int found = 0;
    char *token = strtok(sentence, " ");

    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            found = 1;
            break;
        }
        token = strtok(NULL, " ");
    }

    // Display the result
    if (found) {
        printf("The word '%s' was found in the sentence.\n", word);
    } else {
        printf("The word '%s' was not found in the sentence.\n", word);
    }

    return 0;
}
