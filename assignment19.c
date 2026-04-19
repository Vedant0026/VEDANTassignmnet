#include <stdio.h>
#include <string.h>

#define MAX 100


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct EMPLOYEE {
    char name[50];
    char designation[50];
    char gender;   
    int day, month, year; 
    float salary;
};

void countEmployees(int n);
void countGender(struct EMPLOYEE emp[], int n);
void salaryAbove10k(struct EMPLOYEE emp[], int n);
void asstManager(struct EMPLOYEE emp[], int n);

int main() {
    struct EMPLOYEE emp[MAX];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);
    clearInputBuffer();

    for(i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Name: ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        
        size_t len = strlen(emp[i].name);
        if (len > 0 && (emp[i].name[len - 1] == '\n' || emp[i].name[len - 1] == '\r')) {
            emp[i].name[len - 1] = '\0';
            len--;
        }
        if (len > 0 && emp[i].name[len - 1] == '\r') {
            emp[i].name[len - 1] = '\0';
        }

        printf("Designation: ");
        fgets(emp[i].designation, sizeof(emp[i].designation), stdin);
        len = strlen(emp[i].designation);
        if (len > 0 && (emp[i].designation[len - 1] == '\n' || emp[i].designation[len - 1] == '\r')) {
            emp[i].designation[len - 1] = '\0';
            len--;
        }
        if (len > 0 && emp[i].designation[len - 1] == '\r') {
            emp[i].designation[len - 1] = '\0';
        }

        printf("Gender (M/F): ");
        scanf(" %c", &emp[i].gender);
        clearInputBuffer();

        printf("Date of Joining (dd mm yyyy): ");
        scanf("%d %d %d", &emp[i].day, &emp[i].month, &emp[i].year);
        clearInputBuffer();

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        clearInputBuffer();
    }

    countEmployees(n);
    countGender(emp, n);
    salaryAbove10k(emp, n);
    asstManager(emp, n);

    return 0;
}

void countEmployees(int n) {
    
    printf("Total number of employees: %d\n", n);
   
}

void countGender(struct EMPLOYEE emp[], int n) {
    int male = 0, female = 0, i;

    for(i = 0; i < n; i++) {
        if(emp[i].gender == 'M' || emp[i].gender == 'm')
            male++;
        else if(emp[i].gender == 'F' || emp[i].gender == 'f')
            female++;
    }

    printf("\nMale employees = %d\n", male);
    printf("Female employees = %d\n", female);
}

void salaryAbove10k(struct EMPLOYEE emp[], int n) {
    int i, count = 0;
    printf("\nEmployees with salary above 10000:\n");
   

    for(i = 0; i < n; i++) {
        if(emp[i].salary > 10000) {
            printf("Name: %s | Salary: %.2f\n", emp[i].name, emp[i].salary);
            count++;
        }
    }
    
    if (count == 0) {
        printf("No employees found.\n");
    }
}

void asstManager(struct EMPLOYEE emp[], int n) {
    int i, count = 0;
    printf("\nEmployees with designation 'Asst Manager':\n");
  

    for(i = 0; i < n; i++) {
        if(strcmp(emp[i].designation, "Asst Manager") == 0) {
            printf("Name: %s | Salary: %.2f\n", emp[i].name, emp[i].salary);
            count++;
        }
    }
    
    if (count == 0) {
        printf("No employees found.\n");
    }
}
