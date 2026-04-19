#include <stdio.h>

int main() {
    int num, original, remainder;
    int sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    original = num;

    if (num < 100 || num > 999) {
        printf("Please enter a valid 3-digit number.\n");
        return 0;
    }


    while (num != 0) {
        remainder = num % 10;
        sum += remainder * remainder * remainder;
        num /= 10;
    }

    if (sum == original)
        printf("%d is an Armstrong number.\n", original);
    else
        printf("%d is NOT an Armstrong number.\n", original);

    return 0;
}
