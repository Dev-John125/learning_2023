// 1. Write a program to print exponent part of double variable in hexadecimal and binary format.
// lets say we have x = 0.7, the exponent in hex is 0x3FE and 0b01111111110
// You may use the below link to validate you output
// https://baseconvert.com/ieee-754-floating-point 
// First 12 bits in hex binary and first 3 bits in hex

#include <stdio.h>

void print_exponent(double x) 
{
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long value = *ptr;
    
    
    // To isolate the bits representing the exponent portion, we perform 
    // a right shift operation by 52 positions (52 to 62 i.e total of 11 bits 
    // represents the exponent). 0x7FF is a mask that consists of 11 bits set to 1
    // This step is done to eliminate any potential bits beyond the exp field.
    unsigned long long exponent = (value >> 52) & 0x7FF;   

    printf("Exponent in hexadecimal: 0x%llx\n", exponent);
    printf("Exponent in binary: 0b");
    
    for (int i = 11; i >= 0; i--) 
    {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");
}

int main() 
{
    double x;
    printf("Enter a double type value: ");
    scanf("%lf", &x);
    print_exponent(x);
    
    return 0;
}
