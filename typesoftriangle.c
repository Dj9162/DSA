#include<stdio.h>
int main()
{
    float x,y,z;
    printf("Enter first side of triangle: ");
    scanf("%f",&x);
    printf("Enter second side of triangle: ");
    scanf("%f",&y);
    printf("Enter third side of triangle: ");
    scanf("%f",&z);
    if (x==y & x==z)
    {
        printf("Your triangle is equilateral");
    }
    if (x==y&x!=z||x==z&x!=y||y==z&y!=x)
    {
        printf("Your triangle is isosceles\n");
        
    }
    else if (x!=y & x!=z & y!=z)
    {
        printf("Your triangle is scalene\n");
    }
    if (x*x==y*y+z*z || y*y==x*x+z*z || z*z==x*x+y*y )
    {
        printf("And your triangle is also right angled triangle");
    }
    return 0;
}