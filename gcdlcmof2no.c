#include <stdio.h>
int lcm(int a, int b)
{
    int k=1;
    if (a < b)
    {
        for (int i = 1; i <a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    else
    {
        for (int i = 1; i <b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    return (a * b) / k;
}
int gcd(int a,int b)
{
    int k=1;
    if (a < b)
    {
        for (int i = 1; i <=a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    else
    {
        for (int i = 1; i <=b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    return k;
}
int main()
{
    int x, y;
    printf("Enter first number: \n");
    scanf("%d", &x);
    printf("Enter second number: \n");
    scanf("%d", &y);
    printf("LCM: %d\n", lcm(x, y));
    printf("GCD: %d\n", gcd(x, y));

    return 0;
}
