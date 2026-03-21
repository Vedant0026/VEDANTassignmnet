#include <stdio.h>

int main() {
    int num, remainder, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while(num != 0) {
        remainder = num % 10;          // get last digit
        reverse = reverse * 10 + remainder; // build reverse number
        num = num / 10;               // remove last digit
    }

    printf("Reversed number = %d", reverse);

    return 0;
}