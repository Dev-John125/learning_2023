#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int k) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == k) 
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, i, k, loc;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &k);

    loc = linearSearch(arr, size, k);

    if (loc != -1) 
    {
        printf("Element found at position %d\n", loc + 1);
    } 
    else 
    {
        printf("Element not found\n");
    }

    return 0;
}
