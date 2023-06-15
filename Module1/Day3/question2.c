// 2. Prints Bits:
// Scan a 32bit integer and prints its bits.

// << - left shift, >> - right shift

#include <stdio.h>

void printBits(unsigned int num) 
{
    int i;
    unsigned int mask = 1 << 31;  // 00..(31 Os)..001 -> // 1000..(31 0s)..00

    for (i = 0; i < 32; i++) 
    {
        if (num & mask)
            printf("1");
        else
            printf("0");

        mask >>= 1;  // Shift the mask to the right by 1 position
    }
    printf("\n");
}

int main() 
{
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);                // %u is used for unsigned decimal int

    printf("The decimal number in bits : \n");
    printBits(num);

    return 0;
}
