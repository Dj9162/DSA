#include<stdio.h>
#define PI 3.14 
#define SQUARE(r) r*r
int main()
{
     float a= PI;
     int r = 4;
     printf("%f\n",a);
    // printf("%f",PI);
    printf("Area: %f",PI * SQUARE(r));
    return 0;
}