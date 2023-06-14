// 4. Write a function to accept an integer (32 bits) and operation type to do the following and return the result to main function.
//     - Set 2 bits from nth bit position, if operation type is 1
//     - Clear 3 bits from nth bit position, if operation type is 2
//     - Toggle MSB, if operation type is 3
//    You can consider the below function prototype,
//     - bit_operations(int num, int oper_type, int pos);


#include <stdio.h>

unsigned long int bit_operations(unsigned long int num, int oper_type, int pos) 
{
    
    unsigned long int result;
    switch (oper_type) 
    {
        case 1:  
            result = num | (0x3 << pos);   // 0x3 is 00000011 -> used to set 2 bits from nth position
            break;
        case 2:  
            result = num & ~(0x7 << pos);  // 0x7 is 00000111 -> used to clear 3 bits from nth position
            break;
        case 3:  
            result = num ^ (1 << 31);   // Toggle Most Significant Bit (left most bit)
            break;
        default:  
            result = -1;   //Invalid Operation
            break;
    }

    return result;
}

int main() 
{
    unsigned long int num, result;
    int oper_type, pos;
    printf("Enter an integer: ");
    scanf("%lu", &num);
    printf("%lu", num);
    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);

    if (oper_type == 1 || oper_type == 2) 
    {
        printf("Enter the bit position: ");
        scanf("%d", &pos);
    }

    result = bit_operations(num, oper_type, pos);

    switch (oper_type) 
    {
        case 1:
            printf("The result after setting 2 bits from position %d is : %lu\n", pos, result);
            break;
        case 2:
            printf("The result after clearing 3 bits from position %d is : %lu\n", pos, result);
            break;
        case 3:
            printf("The result after toggling MSB is : %lu\n", result);
            break;
        default:
            printf("Invalid operation type\n");
            break;
    }

    return 0;
}
