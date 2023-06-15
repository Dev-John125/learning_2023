// 1. Patern Generator:
// Write a program to print the given pattern below using 3 functions (1st to accept n and to print from 1 to n, 2nd to accept n and print spaces in between, 3rd to accept the n and print from n to 1)
// 1234554321
// 1234  4321
// 123    321
// 12      21
// 1        1

#include <stdio.h>

void pattern1_to_N( int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%d", i);
    }
}

void patternSpaces(int n)
{
    int i;
    for(i = 1; i <= n ; i++)
    {
        printf(" ");
    }
}

void patternN_to_1(int n)
{
    int i;
    for(i = n; i >= 1; i--)
    {
        printf("%d", i);
    }
}

int main()
{
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = n; i >= 1; i--)
    {
        pattern1_to_N(i);
        patternSpaces(2*(n-i));
        patternN_to_1(i);
        printf("\n");
    }

    return 0;
}