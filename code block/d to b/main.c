#include<stdio.h>
#include<math.h>
int main()
{
    int n=4,d,b=0;
    //int b[32];
//    printf("Enter: ");
//    scanf("%d",&n);
    int c=0;
    while (n>0)
    {
        d=n%2;
        b=b+d*pow(10,c);
        //b[c]=d;
        n=n/2;
        c++;
    }
//    for (int i=c-1;i>=0 ;i--)
//    {
//        printf("%d",b[i]);
//    }
    printf("%d",b);
    return 0;
}

