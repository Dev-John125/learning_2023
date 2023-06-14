// 1. Write a function to find biggest of 2 numbers using 
//     - if else
//     - ternary operator

#include<stdio.h>

int find_biggest_if_else(int a, int b)
{
    int result;

    if(a > b)
    {
        result = a;
    }
    else
    {
        result = b;
    }

    printf("The biggest number found using if else is : %d\n", result);
}

int find_biggest_ternary(int a, int b)
{
    int result = (a > b) ? a : b;
    printf("The biggest number found using ternary operation is : %d\n", result);
}

int main()
{
    int num1, num2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    find_biggest_if_else(num1,num2);
    find_biggest_ternary(num1,num2);

    return 0;
}