#include <stdio.h>
int main()
{

    printf("Prime numbers below 1000 are:\n");
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                if (i == j)
                {
                    printf("%d\n", i);
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}