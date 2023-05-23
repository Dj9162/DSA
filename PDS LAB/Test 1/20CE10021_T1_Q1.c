/* C program to to calculate infinite series of cos x
   where, cos x = 1 - x^2/2! + x^4/4! .................
         -1<x<1
*/
#include<stdio.h>
int main()
{
    printf("This program is to print sum of infinite series of cosx\n where, cos x = 1 - x^2/2! + x^4/4! .................\n");
    float x,m;
    printf("Enter a Real number x between -1 to 1 and press enter: ");              //Asking user to enter x.
    scanf("%f",&x);
    double f = 1, v =1, p = 1, d = 1,s;                                             //declaring some variables
                                                                                    //here,f is to calculate factorial,p is to calculate power of x each time
                                                                                    //d is to determine sign of each terms,s is to calculate value of each terms
                                                                                    //v is calculate value of whole series after each term
    m=x;
    for (int i = 1; i < 50  ; i++)                                                  //Taking 50 as end term because At that term value of s definitely will be less then 10^-5
    {
        f = f * (2 * i - 1) * (2 * i);                                              // Calculating factorial
        p = p * x * x;                                                              // Determining power after each term
        d = d * -1;                                                                 // Determining sign of each terms
        s= p/f;                                                                     // Calculating value of each terms
        if(s<=0.00001)                                                              // If value of any term become less than 10^-5 then loop will be break
        break;
        v = v + d * s;                                                              // Calculating whole value of series

    }
    printf("Value of infinite series of cosx where x=%f is %lf",m,v);
    return 0;
}
