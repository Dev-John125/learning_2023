// 5. To find the difference between even and odd indexed elements

#include <stdio.h>
#include <stdlib.h>

int findIndexedDifference(int array[], int size)
{
    int i, sumOddIndex = 0, sumEvenIndex = 0;

    for(i = 0; i < size ; i++)  
    {
        if(i % 2 == 0)
        {
            sumEvenIndex += array[i];
        }
        else
        {
            sumOddIndex += array[i];
        }
    }

    return abs(sumEvenIndex - sumOddIndex);
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

    ans = findIndexedDifference(arr, n);

    printf("Difference: %d\n", ans);

    return 0;
}