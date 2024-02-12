#include <stdio.h>

int main() {
    int num;
	
	int count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    int origNum = num;
    printf("You entered: %i\n", num);

	while (origNum != 0) {
        origNum /= 10;	
        count++;
    }

    // Reverse the digits
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10; // gets the last dig
        reversed = reversed * 10 + digit; // moves any previous digets up 
		// and adds the new diget to the ones position
        num /= 10; // moves the ones position into decimal
    }
    
	char formatString[count + 5];
	sprintf(formatString, "%%0%dd", count);
	printf("The reversed number is: ");
    printf(formatString, reversed);

    return 0;
}
