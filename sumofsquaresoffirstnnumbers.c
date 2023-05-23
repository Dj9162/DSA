#include<stdio.h>
int main()
{
    int n;
    int k=0;
    printf("Enter number of natural numbers you want: ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        int j;
        printf("Enter %d natural number: ",i);
        scanf("%d",&j);
        k=k+j*j;
    }
    printf("Your sum of squares of natural nambers are: %d ",k);
    
    return 0;
}