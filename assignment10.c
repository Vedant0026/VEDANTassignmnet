#include <stdio.h>
#include <math.h>


long long factorial(int n) {
    long long fact = 1;
    int i;
    if (n < 0) {
        return -1; 
    }
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int choice;
    double num1, num2, result;
    int n;

    do {
        printf("\n===== Simple Calculator =====\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Power (x^y)\n");
        printf("6. Factorial (x!)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result = %.2lf\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result = %.2lf\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result = %.2lf\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0)
                    printf("Result = %.2lf\n", num1 / num2);
                else
                    printf("Error! Division by zero.\n");
                break;

            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result = %.2lf\n", result);
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%d", &n);
                if (factorial(n) == -1)
                    printf("Error! Factorial of negative number not defined.\n");
                else
                    printf("Result = %lld\n", factorial(n));
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 7);

    return 0;
}
