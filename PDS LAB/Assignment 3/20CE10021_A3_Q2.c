/* C program to check whether the given number is perfect or not
 */
#include<stdio.h>
int main()
{
    int c=2,sum=1,n;                                        //Declaring some integer variables
    printf("Enter a natural number: ");                     // Asking user to input a natural number
    scanf("%d",&n);
    while(c*c<=n)                                           //Checking condition
    {
        if (n%c==0)                                         //checking condition that c is factor of n or not
        {
            if(c*c!=n)                                      // Checking whether the c is square of n or not
                sum = sum + c + n/c;                        // Adding the its two factors at one time one itself c and another is number if that multiply by c then itself n will come
            else
                sum=sum+c;                                  // Adding factor to get number itself
        }
    c++;
    }
     if (sum == n && n != 1)                               // Checking whether the sum of all factors is equal to the number itself or not
        printf("The given number is perfect number");
     else
        printf("The given number is not perfect");
    return 0;
}
