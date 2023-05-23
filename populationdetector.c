#include<stdio.h>
int main()
{
    int k=9000;
    int x;
    printf("Enter number of years after which you want to see population: ");
    scanf("%d",&x);
    for (float i = 1; i <= x; i++)
    {
        k=k+k*0.15;
    }
    printf("Population will become %d after %d years\n",k,x);
    printf("Population of town will surpass 50000 after 13 years");
    return 0;
}