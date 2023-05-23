/*  C program to solve following expressions:
    a) K = x++ + ++y
    b) H = ++x + y++ - z--
    c) S = ++x + --y * ++z
*/
#include<stdio.h>
int main()
{
    int x,y,z,K,H,S;                                                                       //Declaration of all required variables.
    printf("Enter the value of natural number x: ");                                       //Asking user to enter the value of x
    scanf("%d",&x);                                                                        //storing inputed value of x
    printf("Enter the value of natural number y: ");                                       //Asking user to enter the value of y
    scanf("%d",&y);                                                                        //storing inputed value of y
    printf("Enter the value of natural number z: ");                                       //Asking user to enter the value of z
    scanf("%d",&z);                                                                        //storing inputed value of z
    printf("As you entered the value of\n x = %d\n y = %d\n z = %d\n",x,y,z);              //printing the values of x,y and z
    K = x++ + ++y;                                                                         //expressions as given in question
    H = ++x + y++ - z--;
    S = ++x + --y * ++z;
    printf("So Required values of\n K = x++ + ++y = %d\n",K);                              //Printing the value of K
    printf(" H = ++x + y++ - z-- = %d\n",H);                                                //Printing the value of H
    printf(" S = ++x + --y * ++z = %d\n",S);                                                //Printing the value of S
    return 0;
}
