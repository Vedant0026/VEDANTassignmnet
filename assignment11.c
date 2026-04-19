#include <stdio.h>
#include <math.h>


int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


long long factorial(int n) {
    long long fact = 1;
    if (n < 0)
        return -1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void primeFactors(int n) {
    printf("Prime factors: ");
    if (n <= 1) {
        printf("Not defined");
        return;
    }

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 0)
        printf("Square root = %.2f\n", sqrt(num));
    else
        printf("Square root not defined for negative numbers\n");

   
    printf("Square = %d\n", num * num);

    
    printf("Cube = %d\n", num * num * num);

    if (isPrime(num))
        printf("The number is Prime\n");
    else
        printf("The number is Not Prime\n");

    long long fact = factorial(num);
    if (fact == -1)
        printf("Factorial not defined for negative numbers\n");
    else
        printf("Factorial = %lld\n", fact);

    primeFactors(num);
    printf("\n");

    return 0;
}
