/*  C program to print pattern of upper inverted triangle lower triangle as given below:
         * * *
         * *
         *
         #
         # #
         # # #
*/
#include<stdio.h>
int main()
{
    printf("This program is to print a pattern\n");
    int n;                                                                     //To store the value of row
    printf("Enter a Natural number which will be total row of pattern: ");
    scanf("%d",&n);
                                                                               // Here this to print upper section
    for (int i = n; i >0; i--)                                                 //To print inverted triangle up to n row
    {
        for (int j = 0; j < i; j++)
        {
            if(j==i-1)                                                         //This is when row is equal to end then only star should be print
                printf("*");
            else                                                               //Otherwise one star and one space is printed
                printf("* ");
        }
        printf("\n");                                                          //To change the line
    }
                                                                               //To print lower section
    for (int i = 0; i <=n; i++)                                                //To print triangle up to n row
    {
        for (int j = 0; j <i; j++)
        {
            if(j==i-1)                                                         //This is when row is equal to end then only one hash should be printted
                printf("#");
            else                                                               //Otherwise one hash and one space is printed
                printf("# ");
        }
        printf("\n");                                                          //To change the line
    }
    return 0;
}
