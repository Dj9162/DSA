#include<stdio.h>
char triangular_pattern()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <i; j++)
        {
            printf("*");
        }
        //The below programme is for same pattern but side by side.
        // int s=10-2*i;
        // for (int j = 0; j < s; j++)
        // {
        //     printf(" ");
        // }
        // for (int j = 0; j < i; j++)
        // {
        //     printf("*");
        // }
        printf("\n");
        
        
    }
    
}
char reverse_triangular_pattrn()
{
    for (int i = 5; i >0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}
int main()
{
    int s;
    printf("Type 1 for triangular pattern\n Type 0 for reversal triangular pattern: ");
    scanf("%d", &s);
    if (s==1)
    {
        triangular_pattern();
    }
    else if(s==0)
    {
        reverse_triangular_pattrn();
    }
    else
    {
        printf("Wrong Input");
    }
    return 0;
}