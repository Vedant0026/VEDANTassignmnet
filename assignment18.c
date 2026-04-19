#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int i, length = 0, isPalindrome = 1;

    
    printf("Enter a string: ");
    gets(str1);

    
    for(i = 0; str1[i] != '\0'; i++) {
        length++;
    }
    printf("Length of string = %d\n", length);

   
    for(i = 0; i < length; i++) {
        temp[i] = str1[length - i - 1];
    }
    temp[length] = '\0';
    printf("Reversed string = %s\n", temp);

    
    printf("Enter another string to compare: ");
    gets(str2);

    if(strcmp(str1, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    
    for(i = 0; i < length; i++) {
        if(str1[i] != str1[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome)
        printf("String is a palindrome\n");
    else
        printf("String is not a palindrome\n");

    
    printf("Enter substring to check: ");
    gets(str2);

    if(strstr(str1, str2) != NULL)
        printf("Substring found\n");
    else
        printf("Substring not found\n");

    return 0;
}
