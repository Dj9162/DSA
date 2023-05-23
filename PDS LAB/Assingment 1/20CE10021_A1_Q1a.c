/* C code to solve expression:
X=1.234*10^5 +7.5 * 10^(-3)
Z = 19.2 * sin(25) + (5.6 + 12 / 7.2) * 10^5
*/
#include<stdio.h>
#include<math.h>                                               //This is used here to use Trigonometric function such as sin and power function
                                                               //sin function is used as sin(angle in radian)
int main()
{
    double X;                                                  //declared X as double because it can be in decimal number
    double Z;                                                  //declared Z as double
    X = 1.234 * pow(10,5) + 7.5 * pow(0.1,3);                  //This is arithmetic expression as given in question.
    Z = 19.2 * sin(25) + ( 5.6 + (12 / 7.2) ) * pow(10,5);     //This is arithmetic expression as given in question
    printf("Your required value of X is: %lf\n",X);              //This is used to print the value of X
    printf("The required value of Z is %lf\n",Z);                //Here value of Z is printed
    return 0;
}
