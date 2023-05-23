/* C program to print all Fibonacci series number up to number entered by user
*/
#include <stdio.h>
int fib_recursive(int n)                                           //function to find all Fibonacci number up to n
{
    if (n == 0)                                          //Initializing first and second term as 1
    {
        return 0;
    }
    else if (n ==1)
    {
        return 1;
    }
    
    else
    {
        return fib_recursive(n - 1) + fib_recursive(n - 2);          // using recursive function to calculate Fibonacci series as The k-th Fibonacci number f(k) = f(k-1) + f(k-2), k >2
    }
}
int main()
{
    int n,j=0;                                                       //n is to store number entered by user and j is to take all natural number
    printf("Enter number of term you want: ");
    scanf("%d", &n);
    printf("Your required Fibonacci series is: ");
    for ( int i = 1 ; i <= n ; i++ )                                 // To print Fibonacci series up to n
   {
      printf("%d ", fib_recursive(j));
      j++;
   }
    return 0;
}

