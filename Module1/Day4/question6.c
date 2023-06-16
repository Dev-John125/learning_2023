// 6. Toggle uppercase char to lowercase char in a string


#include <stdio.h>
#include <ctype.h>

void toggleCase(char *str)
{
    int i;

    while (*str != '\0')
    {
        if (islower(*str))
            *str = *str - 32;
        else if (isupper(*str))
            *str = *str + 32;
        str++;
    }
}

int main()
{
    char str[100];

    printf("Enter a string to toggle case: ");
    fgets(str, sizeof(str), stdin);

    toggleCase(str);
    
    printf("Modified String: %s\n", str);

    return 0;
}