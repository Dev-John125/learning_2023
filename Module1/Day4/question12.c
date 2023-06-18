// 12 Decimal to Binary / Octal / Hex conversion

#include<stdio.h>
void decimalToBinary(int num)
{
    int bin[32], i, length = 0;

    for(i = 0; num > 0; i++)
    {
        bin[i] = num % 2;      // store 0 or 1
        num /= 2 ;
        length++;
    }

    printf("Binary Form: ");
    for(i = length - 1 ; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }

    printf("\n");
}

void decimalToOctal(int num)
{
    int octal[60], i, length = 0;

    for(i = 0; num > 0; i++)
    {
        octal[i] = num % 8;      // store 0-7
        num /= 8 ;
        length++;
    }

    printf("Octal Form: 0o");
    for(i = length - 1; i >= 0; i--)
    {
        printf("%d", octal[i]);
    }

    printf("\n");

}

void decimalToHex(int num)
{
    char hex[100];
    int i, length = 0, rem;

    for(i = 0; num > 0; i++)
    {
        rem = num % 16;      // store 0-9 and A-F

        if(rem < 10)
        {
            hex[i] = rem + 48;
        }
        else
        {
            hex[i] = rem + 55;    // if 10 then 55 + 10 = 65 which is A
        }
        
        num /= 16 ;
        length++;
    }

    printf("Hexadecimal Form: 0x");
    for(i = length - 1; i >= 0; i--)
    {
        printf("%c", hex[i]);
    }

    printf("\n");

}

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);
    decimalToOctal(decimal);
    decimalToHex(decimal);

    return 0;
}