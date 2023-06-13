// 4. Write a simple calculator program which should accept inputs in the same order.
//     - Operand 1
//     - Operator
//     - Operand 2
// The order of scan should be same, for example, you should first scan in the following order.
// printf("Enter Number1: );
// Scan the first number form the user.
// printf("Enter the operator: );
// Scan the operator from the user.
// printf("Enter Number2: );
// Scan the second number form the user.

#include<stdio.h>
#include<stdlib.h>

void calculator(float operand1, float operand2, char operator)
{
    float result;
    switch(operator)
    {
        case '+' : 
            result = operand1 + operand2;
            break;
        case '-' :
            result = operand1 - operand2;
            break;
        case '*' :
            result = operand1 * operand2;
            break;
        case '/' :
            if(operand2 == 0)
            {
                printf("Division by Zero is not allowed\n");
                exit(0);
            }
            result = operand1 / operand2;
            break;
        case '%' :
            result = (int)operand1 % (int)operand2;
            break;
        default :
            printf("Invalid Operation");
            break;
    }

    printf("The result is : %.2f\n", result);
}

int main()
{
    float operand1, operand2;
    char operator;

    printf("Enter the first number: ");
    scanf("%f", &operand1);
    printf("Enter the operator: ");
    scanf(" %c", &operator);   //Include a space here to avoid skipping scanf operation here
    printf("Enter the second number: ");
    scanf("%f", &operand2);

    calculator(operand1, operand2, operator);
    return 0;
}

//%c takes the trailing \n character as input so skips the scan operation.
//To avoid that we add a space in front of %c