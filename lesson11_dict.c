// Build a simple dictionary in C by completing this code
#include <stdio.h>


size_t strlenn (char *str) {
    size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}



// Implement this function!
// Did you already complete this function in the previous lesson practice set?
int equalStrings(char str1[], char str2[]) {
    int size1 = strlenn(str1);
    int size2 = strlenn(str2);
    
    if (size1 != size2)
        return 0; // Strings are different lengths
    
    for (int i = 0; i < size1; i++) {
        if (str1[i] != str2[i])
            return 0; // Strings are different at position i
    }
    
    return 1; // Strings are equal
}



struct entry {
    char word[15];
    char definition[50];
};

// Implement this function!
// Note that the first argument is an array of struct entry
// This function should make use of equalStrings()
int lookup(struct entry dictionary[],  char searchTerm[], int entries) {
  // Write code so that this function returns the index of searchTerm if it is in the dictionary, if not, it should return -1
    // In terms of a search algorithm, it should be fine to just carry out a linear search
    // printf("%s",dictionary[0].word);
    for (int i = 0; i < entries; i++) {
        printf("%s in %s \n", searchTerm, dictionary[i].word );
        if (equalStrings(dictionary[i].word, searchTerm) == 1) return i;
    }
    
    return -1;
}

// main() is complete
// study how an array of structures is initialized
// Perhaps you can add a few more entries to dictionary
int main() {
     struct entry dictionary[100] = {
        { "abyss", "a bottomless pit" },
        { "acumen", "mentally sharp; keen" },
        { "addle", "to become confused" },
        { "affix", "to append; attach" },
        { "ajar", "partially opened" }
    };

    char word[10];
    int entries = 5;
    int entry;
    
    printf("Enter word: ");
    scanf("%14s", word);
    entry = lookup(dictionary, word, entries);
    
    if (entry != -1) {
        printf("%s\n", dictionary[entry].definition);
    } else {
        printf("Word not found!\n");
    }

    return 0;
}