// 1. Use structures to find the volume and the total surface area of the box. 
//    You need to access the members of the structure with the help of a structure pointer:
//     a. With the help of (*) asterisk or indirection operator and (.) dot operator.
//     b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.

#include <stdio.h>

struct Box 
{
    float length;
    float width;
    float height;
};

typedef struct Box Box;


float calcVolume(Box* ptr)
{
    float v =  (*ptr).length * (*ptr).width * (*ptr).height;   // using asterisk
    return v;
}


float calcSArea(Box* ptr)
{
    float sa = 2 * ((*ptr).length * (*ptr).width + (*ptr).length * (*ptr).height + (*ptr).width * (*ptr).height);         // using asterisk
    return sa;
}

int main() 
{
    Box b1;
    Box* ptr = &b1;
    
    printf("Enter the length width and height of the box: ");
    scanf("%f %f %f", &b1.length, &b1.width, &b1.height);


    printf("Volume: %.2f\n", calcVolume(ptr));
    printf("Surface Area: %.2f\n", calcSArea(ptr));
    
    return 0;
}
