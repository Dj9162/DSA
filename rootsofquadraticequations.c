#include<stdio.h>
int main()
{
    int a,b,c,d,e;
    printf("Quadratic equation of the form: ax^2+bx+c=0\n");
    printf("Enter value of 'a': \n");
    scanf("%d",&a);
    printf("Enter value of 'b': \n");
    scanf("%d",&b);
    printf("Enter value of 'c': \n");
    scanf("%d",&c);
    d=(-b+(b*b-4*a*c))/2*a;
    e=(-b-(b*b-4*a*c))/2*a;
    printf("The roots of your quadratic equation are %d and %d\n",d,e);
    return 0;
}
