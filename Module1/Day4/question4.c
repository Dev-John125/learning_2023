// 4. To find the difference between even and odd elements

#include <stdio.h>
#include <stdlib.h>

int findDifference(int array[], int size)
{
    int i, sumOdd = 0, sumEven = 0;

    for(i = 0; i < size ; i++)  
    {
        if(array[i] % 2 == 0)
        {
            sumEven += array[i];
        }
        else
        {
            sumOdd += array[i];
        }
    }

    return abs(sumEven - sumOdd);
}

int main()
{
    int n, i, ans;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ans = findDifference(arr, n);

    printf("Difference: %d\n", ans);

    return 0;
}