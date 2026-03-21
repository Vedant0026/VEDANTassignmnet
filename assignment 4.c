#include <stdio.h>

int main() {
    float basicPay, hra, ta, grossSalary, tax, netSalary;

    printf("Enter Basic Pay: ");
    scanf("%f", &basicPay);

    hra = 0.10 * basicPay;
    ta = 0.05 * basicPay;

    grossSalary = basicPay + hra + ta;
    tax = 0.02 * grossSalary;

    netSalary = grossSalary - tax;

    printf("\nGross Salary = %.2f", grossSalary);
    printf("\nProfessional Tax = %.2f", tax);
    printf("\nNet Salary = %.2f", netSalary);

    return 0;
}