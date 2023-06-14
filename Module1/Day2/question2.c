//Write a program to swap any type of data passed to an function.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// We will use void pointer to hold any type of data
// size_t is the type returned by the sizeof operator and is 
// frequently used in the standard library to describe sizes and counts.
void swap(void *a, void *b, size_t size) 
{
    char* temp =(char*)malloc(size); // Temp data to hold values

    memcpy(temp, a , size);  // (destination, source, size of datatype of a)
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

int main()
{
    int num1, num2;
    float fnum1, fnum2;
    double dnum1, dnum2;

    int option;
    printf("Enter the type of data\n1.Integer\n2.Double\n3.Float\nEnter 1,2 or 3 :");
    scanf("%d",&option);

    switch (option)
    {
        case 1:
            printf("Enter 2 numbers (int): ");
            scanf("%d %d", &num1, &num2);
            printf("Before Swapping: num1 = %d, num2 = %d\n", num1, num2);
            swap(&num1, &num2, sizeof(int));
            printf("After Swapping: num1 = %d, num2 = %d\n", num1, num2);
            break;
        case 2:
            printf("Enter 2 numbers (double): ");
            scanf("%lf %lf", &dnum1, &dnum2);
            printf("Before Swapping: num1 = %lf, num2 = %lf\n", dnum1, dnum2);
            swap(&dnum1, &dnum2, sizeof(double));
            printf("After Swapping: num1 = %lf, num2 = %lf\n", dnum1, dnum2);
            break;
        case 3:
            printf("Enter 2 numbers (float): ");
            scanf("%f %f", &fnum1, &fnum2);
            printf("Before Swapping: num1 = %f, num2 = %f\n", fnum1, fnum2);
            swap(&fnum1, &fnum2, sizeof(float));
            printf("After Swapping: num1 = %f, num2 = %f\n", fnum1, fnum2);
            break;
        default:
            printf("Invalid Option\n");
            break;


    }
    
    return 0;
}