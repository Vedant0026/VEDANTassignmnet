#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int choice;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    do {
        printf("\n----- STRING OPERATIONS MENU -----\n");
        printf("1. Find Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Check Palindrome\n");
        printf("7. Check Substring\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Length of str1 = %lu\n", strlen(str1));
                printf("Length of str2 = %lu\n", strlen(str2));
                break;

            case 2:
                strcpy(temp, str1);
                printf("Copied string (str1 -> temp): %s\n", temp);
                break;

            case 3:
                strcpy(temp, str1);
                strcat(temp, str2);
                printf("Concatenated string: %s\n", temp);
                break;

            case 4:
                if(strcmp(str1, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are NOT equal\n");
                break;

            case 5:
                strcpy(temp, str1);
                strrev(temp);   // Note: works in some compilers (Turbo C)
                printf("Reversed string: %s\n", temp);
                break;

            case 6:
                strcpy(temp, str1);
                strrev(temp);
                if(strcmp(str1, temp) == 0)
                    printf("String is a palindrome\n");
                else
                    printf("String is NOT a palindrome\n");
                break;

            case 7:
                if(strstr(str1, str2) != NULL)
                    printf("'%s' is a substring of '%s'\n", str2, str1);
                else
                    printf("'%s' is NOT a substring of '%s'\n", str2, str1);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}