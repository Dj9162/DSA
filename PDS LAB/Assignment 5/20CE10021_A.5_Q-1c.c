/* C program to print least fraction of a rational number
*/
#include<stdio.h>
void least_fraction(int a,int b)
{
    int k;                                                      // Variable to store final gcd of number
    if (a < b)                                                  // Checking whether numerator is greater or denominator
    {
        for (int i = 1; i <=a; i++)                             // Loop to take all natural numbers less than smaller number to divide
        {
            if (a % i == 0 && b % i == 0)                       //Checking condition that both num and den are divisible or not
            {
                k = i;
            }
        }
    }
    else
    {
        for (int i = 1; i <=b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = i;
            }
        }
    }
    int n,m;                                                     // Initializing variable to store number after divided by its gcd
    n = a / k;
    m = b / k;
            if (m == 1)                                          //checking den of number if it is 1 or not
        {
            printf("Your fraction is: %d",n);
        }
            else if(m == 0)
        {
            printf("Your entered number is infinity");            // Checking den of number if it is 0 or not
        }
            else
            printf("Your required fraction is %d/%d",n,m);         //Printing final least fraction number
}

int main()
{
    int num,den;                                                    //Initializing to store numerator and denomenator of number
    printf("Enter numerator of fraction: ");
    scanf("%d",&num);
    printf("Enter denominator of fraction: ");
    scanf("%d",&den);
    least_fraction(num,den);                                        //Calling function to print least fraction

    return 0;
}
