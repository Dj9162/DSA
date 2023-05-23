#include<stdio.h>
#include<stdlib.h>
struct point
{
    float x;
    float y;
};
struct rect
{
    float length;
    float breadth;
    struct point p[4];
};

int main()
{
    struct rect r;
    printf("Enter the length of rectangle: ");
    scanf("%f", &r.length);
    printf("Enter breadth of rectangle: ");
    scanf("%f",&r.breadth);
    printf("Enter bottom-left corner cordinates x y: ");
    scanf("%f %f",&r.p[0].x,&r.p[0].y);
    r.p[1].x = r.p[0].x + r.length;
    r.p[1].y = r.p[0].y;
    r.p[2].x = r.p[1].x;
    r.p[2].y = r.p[1].y + r.breadth;
    r.p[3].x = r.p[0].x;
    r.p[3].y = r.p[0].y + r.breadth;
    printf("Information of the rectangle:\n Length = %f\n Breadth = %f\n",r.length,r.breadth);
    printf("coordinates of rectangle = {(%.2f,%.2f),(%.2f,%.2f),(%.2f,%.2f),(%.2f,%.2f)}\n",r.p[0].x,r.p[0].y,r.p[1].x,r.p[1].y,r.p[2].x,r.p[2].y,r.p[3].x,r.p[3].y);
    
    return 0;
}