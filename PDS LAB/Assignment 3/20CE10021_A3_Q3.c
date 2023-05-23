/* C program to print twin primes
*/
#include<stdio.h>
int main()
{
    int n,b;
    printf("Enter a natural number: ");
    scanf("%d",&n);
    for (int j = 2; j <= n; j++)
    {
        if (n % j == 0)
        {
            if (n == j)
            {
               for (int i=3;i<=n;i++)
                {
                    for (int j=2;j<= i * i+1;j++);
                    {
                        b=i%j;
                        if (b!=0)
                        {
                            printf("%d,%d\n",i,i);
                        }
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
