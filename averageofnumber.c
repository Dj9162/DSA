#include<stdio.h>
int main()
{
    int n;
    float k=0;
    printf("Enter number of natural numbers you want to find average: ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        float j;
        printf("Enter %d number: ",i);
        scanf("%f",&j);
        k=k+j;
    }
    
    printf("Your average is: %f ",k/n);
    
    return 0;
}