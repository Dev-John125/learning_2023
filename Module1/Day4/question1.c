// 1. To find the sum and average of 1D arrays (set5)

#include <stdio.h>


int findSum(int array[], int size)
{
    int sum = 0, i;

    for(i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

float findAvg(int sum, int size)
{
    float avg = (float) sum / size;
    return avg;
}


int main()
{
    int n, i, sum;
    float avg;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sum = findSum(arr, n);
    avg = findAvg(sum, n);

    printf("The sum is %d\n", sum);
    printf("The average is %.2f\n", avg);

    return 0;
}