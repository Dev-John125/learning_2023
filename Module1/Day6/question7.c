// 2. Write a program to enter two Cartesian coordinate points and display the distance between them.



#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} point;

float calculateDistance(point a, point b) 
{
    float X = b.x - a.x;          // distance = √((x2 – x1)² + (y2 – y1)²)
    float Y = b.y - a.y;
    float soln = sqrt(X * X + Y * Y);     
    return soln;   
}

int main() 
{
    point p1, p2;

    printf("Enter the coordinates of point 1:\n");
    printf("X-coordinate: ");
    scanf("%f", &p1.x);
    printf("Y-coordinate: ");
    scanf("%f", &p1.y);

    printf("Enter the coordinates of point 2:\n");
    printf("X-coordinate: ");
    scanf("%f", &p2.x);
    printf("Y-coordinate: ");
    scanf("%f", &p2.y);

    float distance = calculateDistance(p1, p2);
    printf("The distance between the two points is: %.2f\n", distance);

    return 0;
}
