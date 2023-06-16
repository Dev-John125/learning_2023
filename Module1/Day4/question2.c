// 2. To find the min and max element of 1D arrays (set5)

#include <stdio.h>

void findMinMax(int array[], int size, int *min, int *max)
{
    *min = array[0];    //Pointing min and max to first element of array
    *max = array[0];

    int i;

    for(i = 1; i < size; i++)
    {
        if(array[i] > *max)
        {
            *max = array[i];
        }
        
        if(array[i] < *min)
        {
            *min = array[i];
        }
    }
}

int main()
{
    int n, i, min, max;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, n, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}