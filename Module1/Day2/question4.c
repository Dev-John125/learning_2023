// 4. Write a program to find total number of bits set in a given array.
// Say we have a array of 3 elements
// a[3] = {0x1, 0xF4, 0x10001};
// The total number of set bits in the given array is
// 1 bit in 0x01, 5 in 0xF4, 2 in 0x10001, so the total is 1 + 5 + 2 = 8 bits

// 0x01 = 1 -> 00000001 so 1 bit
// 0xF4 = 244 -> 11110100 so 5 bits
// 0x10001 = 65537 -> 10000000000000001 so 2 bits

#include <stdio.h>

int countBits(int num) // We have to count the no. of bits which is set to 1 in all hex numbers
{
    int count = 0;
    while (num) {
        count += num & 1;  // Bitwise And operation with 1 is performed
        num >>= 1;         // Right shifts the hex number until it becomes 0
    }
    return count;
}

int main() {
    // int array[] = {0x1, 0xF4, 0x10001};
    // int size = sizeof(array) / sizeof(array[0]);

    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the hex numbers: ");  //0x notation can be given or ignored while taking as input
    for(i = 0; i < size; i++)
        fscanf(stdin, "%x", &arr[i]);

    int total = 0;
    for (i = 0; i < size; i++) {
        total += countBits(arr[i]);
    }

    printf("The total number of set bits in the given array is: %d\n", total);

    return 0;
}
