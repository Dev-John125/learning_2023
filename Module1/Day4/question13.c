//13 Binary / Octal / Hex to Decimal Conversion

// Add -lm flag to link the math.h library

#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(const char *binary)
{
    int i, len, power = 0, decimal = 0;

    len = strlen(binary);

    for(i = len - 1; i >= 0 ; i--)
    {
        decimal += (binary[i] - '0') * pow(2, power);
        power++;
    }

    return decimal;
}

int octalToDecimal(const char *octal)
{
    int i, len, power = 0, decimal = 0;

    len = strlen(octal);

    for(i = len - 1; i >= 0 ; i--)
    {
        decimal += (octal[i] - '0') * pow(8, power);
        power++;
    }

    return decimal;
}

int hexToDecimal(const char *hex)
{   
    int i, len, power = 0, decimal = 0;

    len = strlen(hex);

    for(i = len - 1; i >=0 ; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - '0') * pow(16, power);
        } 
        else if (hex[i] >= 'A' && hex[i] <= 'F') 
        {
            decimal += (hex[i] - 'A' + 10) * pow(16, power);
        } 
        else if (hex[i] >= 'a' && hex[i] <= 'f') 
        {
            decimal += (hex[i] - 'a' + 10) * pow(16, power);
        }
        power++;
    }
}

int main()
{
    int option, decimal;
    char number[100];

    printf("Which Conversion do you want to perform?\n1. Octal to Decimal\n2. Hexadecimal to Decimal\n3. Binary to Decimal\nEnter your option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the octal number: ");
            scanf("%s", number);
            decimal = octalToDecimal(number);
            printf("The Decimal number is %d\n", decimal);
            break;

        case 2:
            printf("Enter the hex number: ");
            scanf("%s", number);
            decimal = hexToDecimal(number);
            printf("The Decimal number is %d\n", decimal);
            break;

        case 3:
            printf("Enter the binary number: ");
            scanf("%s", number);
            decimal = binaryToDecimal(number);
            printf("The Decimal number is %d\n", decimal);
            break;
            
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}