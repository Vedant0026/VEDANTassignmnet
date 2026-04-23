#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks[5];
    float percentage;
    char result[20];
    char division[20];
};

int main() {
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n]; // array of structures

    
    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter marks of 5 subjects:\n");
        int total = 0, fail = 0;

        for(j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            total += s[i].marks[j];

            if(s[i].marks[j] < 40) {
                fail = 1;
            }
        }

        
        s[i].percentage = total / 5.0;

        
        if(fail) {
            sprintf(s[i].result, "Fail");
            sprintf(s[i].division, "None");
        } else {
            sprintf(s[i].result, "Pass");

            if(s[i].percentage >= 75)
                sprintf(s[i].division, "Distinction");
            else if(s[i].percentage >= 60)
                sprintf(s[i].division, "First Division");
            else if(s[i].percentage >= 50)
                sprintf(s[i].division, "Second Division");
            else
                sprintf(s[i].division, "Third Division");
        }
    }

    
    printf("\n--- Student Results ---\n");

    for(i = 0; i < n; i++) {
        printf("\nName: %s", s[i].name);
        printf("\nRoll No: %d", s[i].roll);

        printf("\nMarks: ");
        for(j = 0; j < 5; j++) {
            printf("%d ", s[i].marks[j]);
        }

        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nResult: %s", s[i].result);
        printf("\nDivision: %s\n", s[i].division);
    }

    return 0;
}