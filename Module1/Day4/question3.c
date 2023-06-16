// 3. To reverse a given array

#include<stdio.h>

void revArray(int array[], int size)
{
    int first , last = size - 1, temp, i;

    for(first = 0; first < last ; first++, last--)  // last-- done to decrease execution time
    {
        temp = array[first];
        array[first] = array[last];
        array[last] = temp;
    }
}

int main()
{
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    revArray(arr, n);

    printf("\nReversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}