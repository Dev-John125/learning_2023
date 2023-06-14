// 5. Write a function to find the type of the character passed
//     - 'A' to 'Z', return 1
//     - 'a; to 'z', return 2
//     - '0' to '9', return 3
//     - Any Other printable symbols, return 4
//     - Non printable symbols, return 5 

#include <stdio.h>

int findCharacterType(char ch) 
{
    if (ch >= 'A' && ch <= 'Z') 
    {
        return 1;
    } 
    else if (ch >= 'a' && ch <= 'z') 
    {
        return 2;
    } 
    else if (ch >= 48 && ch <= 57) 
    {
        return 3;
    } 
    else if (ch >= 32 && ch <= 126)      // All printable characters lie between 32 to 126, alphabets and numbers will get excluded in the previous statements
    {
        return 4;
    } 
    else 
    {
        return 5;    // Space is not considered here
    }
}

int main() 
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    int type = findCharacterType(ch);

    switch (type) 
    {
        case 1:
            printf("Uppercase letter\n");
            break;
        case 2:
            printf("Lowercase letter\n");
            break;
        case 3:
            printf("Digit\n");
            break;
        case 4:
            printf("Printable symbol\n");
            break;
        case 5:
            printf("Non-printable symbol\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}
