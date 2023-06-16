// 7. Convert string into an integer


#include <stdio.h>

int convertToNumber(char str[])
{
    int number = 0, i = 0;

    while (str[i] != '\0' && str[i] != '\n')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            number = (number * 10) + (str[i] - '0');
        }
        else
        {
            printf("Invalid input\n");
            return 0;
        }
        i++;
    }

    return number;
}

int main()
{
    char str[100];
    int num;

    printf("Enter a string to convert into a number: ");
    fgets(str, sizeof(str), stdin);

    num = convertToNumber(str);
    
    if(num != 0)
    {
        printf("The number is : %d\n", num);
    }

    return 0;
}