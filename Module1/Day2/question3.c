// 3. Write a program to sum every alternate elements of a given array starting for element 0
// For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be 10 + 30 + 50 = 90


#include <stdio.h>

int main()
{
    int size, i, sum = 0;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(i = 0; i < size; i++)
        fscanf(stdin, "%d", &arr[i]);  // To take array input in a single line

    for( i = 0; i < size; i += 2)
    {
        sum += arr[i];
    }

    printf("The sum of alternate numbers is %d\n", sum);

    return 0;
}