/* C code to solve the following expression
Z = 19.2 * sin(25) + (5.6 + 12 / 7.2) * 10^5
*/
#include<stdio.h>
#include<math.h>                                               //This is used here to use Trigonometric function such as sin and power function
                                                               //sin function is used as sin(angle in radian)
int main()
{
    double Z;                                                  //declared Z as double
    Z = 19.2 * sin(25) + ( 5.6 + (12 / 7.2) ) * pow(10,5);     //This is arithmetic expression as given in question
    printf("The required value of Z is %lf",Z);                //Here value of Z is printed
    return 0;
}
