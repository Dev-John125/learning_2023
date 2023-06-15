//3. Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

#include <stdio.h>


int findLargestNumber(int num) 
{   
    int i, j, temp, divisor;
    int maxNum = -1;    // Temp value to store maximum number

    for (i = 0; i < 4; i++) 
    {
        divisor = 1;
        temp = num;

        for (j = 0; j < i; j++) 
        {
            divisor *= 10;
        }

        temp = (num / (divisor * 10)) * divisor + (num % divisor);  // Removing Digits

        if (temp > maxNum) 
        {
            maxNum = temp;
        }
    }

    return maxNum;
}

int main() 
{
    int num, largestNum;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    largestNum = findLargestNumber(num);
    printf("Largest number by deleting a single digit is: %d\n", largestNum);

    return 0;
}
