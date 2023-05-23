/* C code to sum of the squares of  the first n natural numbers
*/
#include<stdio.h>
int main()
{
    int n,sum;                                                                    //n and sum is declared as int because sum of n natural numbers is integer
    printf("Enter a natural number up-to which you want sum of squares: ");       //Here it ask user to enter value of n
    scanf("%d",&n);                                                               //used to store value of n inputed from user
    sum = n * ( 2 * n + 1) * ( n + 1 ) / 6;                                       //formula of sum of squares of n natural numbers is used
    printf("The sum of squares up-to %d is %d",n,sum);                            //value of sum is printed using printf function.
    return 0;
}
