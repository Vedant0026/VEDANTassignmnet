#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int i, fact = 1;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, i, sign = 1;
    float x, sum = 0;

    printf("Enter value of x (in radians): ");
    scanf("%f", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    float power_x = x;  
    long fact = 1;      
    
    for(i = 1; i <= n; i++) {
        if(i > 1) {
            fact *= (2*i - 2) * (2*i - 1);  
            power_x *= x * x;                
        } else {
            fact = 1;
        }
        sum += sign * (power_x / fact);
        sign *= -1;
    }

    printf("Sum of sine series = %.6f\n", sum);

    return 0;
}
