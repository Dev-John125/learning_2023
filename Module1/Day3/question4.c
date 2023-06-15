// 5. Write a program to find both smallest and largest digits in given n numbers
// For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5

#include <stdio.h>

void findDigits(int n, int numbers[]) 
{
    int smallest, largest, i, num, temp, digit;

    for (i = 0; i < n; i++) 
    {
        num = numbers[i];
        temp = num;
        smallest = 9;
        largest = 0;

        while (temp > 0) 
        {
            digit = temp % 10;

            if (digit < smallest) 
            {
                smallest = digit;
            }
            if (digit > largest) 
            {
                largest = digit;
            }

            temp /= 10;
        }

        if (smallest == 9 || largest == 0) 
        {
            printf("Not Valid\n");
        } 
        else 
        {   
            printf("Number = %d ; Smallest Digit = %d ; Largest Digit = %d\n",num, smallest, largest);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int num[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) 
    {
        fscanf(stdin, "%d", &num[i]);
    }

    findDigits(n, num);
    return 0;
}
