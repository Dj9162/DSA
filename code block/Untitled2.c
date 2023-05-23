#include<stdio.h>
#include<math.h>
int main()
{
    int n=0,d=0,m=4;
    for (int i=0;i<4;i++ )
    {
        d=m%2;
        int t=n;
        n= t+ d * pow(10,i);
        m=m/2;

    }
    printf("%d",n);
    return 0;
}
