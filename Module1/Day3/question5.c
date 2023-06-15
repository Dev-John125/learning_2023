// 1. Bit Operations:
// https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

// DS1307 has its time registers in BCD format as shown in the image found in the above link, so 
// a. Write a function to Set, clear and toggle bit of an 8-bit number

// The decimal number is 234. In binary-coded decimal, 234 is written as the following: 2 = 0010, 3 = 0011, 4 = 0100.


#include <stdio.h>

void setBit(unsigned char *bcd, int pos) 
{
    *bcd |= (1 << pos);
}

void clearBit(unsigned char *bcd, int pos) 
{
    *bcd &= ~(1 << pos);
}

void toggleBit(unsigned char *bcd, int pos) 
{
    *bcd ^= (1 << pos);
}

int main() {
    unsigned char bcdNum;
    int posSet, posClear, posToggle;

    printf("Enter the BCD format number in hexadecimal: ");
    scanf("%hhx", &bcdNum);                                   // %hhx specifier used to input hex numbers

    printf("Initial BCD Number: 0x%02hhX\n", bcdNum);  // %02hhX is used for printing unsigned integer hex value 

    printf("Enter the bit position to be set: ");
    scanf("%d", &posSet);
    setBit(&bcdNum, posSet);
    printf("After setting bit %d: 0x%02X\n", posSet, bcdNum);

    printf("Enter the bit position to be cleared: ");
    scanf("%d", &posClear);
    clearBit(&bcdNum, posClear);
    printf("After clearing bit %d: 0x%02X\n", posClear, bcdNum);

    printf("Enter the bit position to be toggled: ");
    scanf("%d", &posToggle);
    toggleBit(&bcdNum, posToggle);
    printf("After toggling bit %d: 0x%02X\n", posToggle, bcdNum);

    return 0;
}

