/*   C code to solve following expression:
      x + ( x + 1 ) + ( x + 2 ) + … + ( x + n )
      where, values of x and n are taken from user
*/
#include<stdio.h>
int main()
{
    int n;                                                                               //n is declared as int.
    int sum1;                                                                            //here sum1 is declared to sum all the n natural number
    float x;                                                                             //x is declared as float
    double sum;                                                                          //sum is declared as double to store total value of sum inside this
    printf("Enter a natural number n: ");                                                //n is asked to input from user
    scanf("%d",&n);                                                                      //n is stored using scanf function
    printf("Enter a real number x: ");                                                   //x is asked to input from user
    scanf("%f",&x);
    sum1 = n * ( n + 1 ) / 2;                                                            //here sum of all natural numbers till n is calculated using sum of natural number formula
    sum = n * x + sum1;                                                                  //Total sum is declared as asked in question
    printf("Your input value of n and x are %d and %f respectively\n",n,x);              //Here values of x and n are printed
    printf("So, Your total sum is %lf",sum);                                             //Here total sum is printed
    return 0;
}
