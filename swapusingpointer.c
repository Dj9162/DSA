#include<stdio.h>
int swap(int* x,int* y)
{
    int c,d;
    c= *x+*y;
    d=*x-*y;
    *x=c;
    *y=d;

}
int main()
{
    int a=55;
    int b=45;
    printf("The value of a is %d\n",a);
    printf("The value of b is %d\n",b);
    swap(&a,&b);
    printf("The value of a now is %d\n",a);
    printf("The value of b now is %d\n",b);

    return 0;
}