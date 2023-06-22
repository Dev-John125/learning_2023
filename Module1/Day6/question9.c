// 4. Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure 
//    to the calling function after modifying the members of structure.

// Here we are modifying the details of a car structure using a pointer as parameter and returning it back to main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char brand[50];
    int year;
}car;

car* modifications(car* vehicle) 
{
    strcpy(vehicle->brand, "Tesla");
    vehicle->year = 2023;
    return vehicle;
}

int main() 
{
    car* vehicle = (car*)malloc(sizeof(car));

    strcpy(vehicle->brand, "Honda");
    vehicle->year = 2016;

    printf("Before modification, the values are as follows :\n");
    printf("Brand: %s\n", vehicle->brand);
    printf("Year: %d\n", vehicle->year);

    car* modifiedV = modifications(vehicle);

    printf("\nAfter modification, the values are as follows :\n");
    printf("Brand: %s\n", modifiedV->brand);
    printf("Year: %d\n", modifiedV->year);

    free(vehicle);
    return 0;
}
