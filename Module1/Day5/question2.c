// 2. Write a C program that uses functions to perform the following operations: 
//      i) Reading a complex number 
//      ii) Writing a complex number 
//      iii) Addition of two complex numbers 
//      iv) Multiplication of two complex numbers 
//   (Note: represent complex number using a structure.)

#include <stdio.h>

struct Complex 
{
    float real;
    float imaginary;
};

typedef struct Complex complex;

void read(complex* ptr) 
{
    printf("Enter the real part of the number: ");
    scanf("  %f", &(ptr->real));

    printf("Enter the imaginary part of the number: ");
    scanf("  %f", &(ptr->imaginary));
}

void write(complex* ptr) 
{
    if (ptr->imaginary < 0)
    {
        printf("Complex number : %.2f - %.2fi\n", ptr->real, -ptr->imaginary);
    }
    else
    {
        printf("Complex number : %.2f + %.2fi\n", ptr->real, ptr->imaginary);
    }
}

complex addNum(complex n1, complex n2) 
{
    complex num;
    num.real = n1.real + n2.real;
    num.imaginary = n1.imaginary + n2.imaginary;

    return num;
}

complex multiplyNum(complex n1, complex n2)        // (a + ib) (c + id) = (ac - bd) + i(ad + bc))
{
    complex num;
    num.real = (n1.real * n2.real) - (n1.imaginary * n2.imaginary);
    num.imaginary = (n1.real * n2.imaginary) + (n1.imaginary * n2.real);
    return num;
}

int main() 
{
    complex num1, num2, sum, product;

    printf("First complex number\n");
    read(&num1);

    printf("\nSecond complex number\n");
    read(&num2);

    sum = addNum(num1, num2);
    product = multiplyNum(num1, num2);

    printf("\nFirst Complex number is \n");
    write(&num1);

    printf("\nSecond Complex number is \n");
    write(&num2);

    printf("\nSum of ");
    write(&sum);

    printf("\nProduct of ");
    write(&product);

    return 0;
}
