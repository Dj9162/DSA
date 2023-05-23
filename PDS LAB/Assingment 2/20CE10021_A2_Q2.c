/* C program to do the following algebraic operations:
    1. Addition
    2. Subtraction
    3. Multiplication
    4. Division
    5. Remainder
    6. L.C.M
    7. H.C.F
*/
#include<stdio.h>
int lcm(int a, int b)                          //function to calculate L.C.M of two numbers
{
    int k=1;
    if (a < b)
    {
        for (int i = 1; i <=a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    else
    {
        for (int i = 1; i <=b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    return (a * b) / k;
}
int gcd(int a,int b)                      //function to calculate H.C.F of two numbers
{
    int k=1;
    if (a < b)
    {
        for (int i = 1; i <=a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    else
    {
        for (int i = 1; i <=b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = k * i;
                continue;
            }
        }
    }
    return k;
}
int main()
{
    char ope;                                                                               // TO take operators
    double x,y,s;                                                                           // To take two real numbers and store the value of all required value
    int r;
    printf("Enter first real number: ");                                                    // Asking user to enter first real number
    scanf("%lf",&x);
    printf("Enter second real number: ");                                                   // Asking user to enter second real number
    scanf("%lf", &y);
    printf(" 1. + for Addition\n 2. - for Subtraction\n 3. * for Multiplication\n");        // Some of hints given to user
    printf(" 4. / for Division\n 5. %% for Remainder\n");
    printf(" 6. L for L.C.M\n 7. H for H.C.F\n");
    printf("Enter any of the above algebraic operator: ");                                  // Asking user to enter operator
    scanf(" %c", &ope);
    if ( ope == '+')                                                                        // to check operator entered from user whether it is + or not
    {
        s = x + y;                                                                          // doing summation
        printf(" Summation: x + y = %lf",s);                                                // Printing summation
    }
    else if ( ope == '-')                                                                   //to check operator entered from user whether it is - or not
    {
        s = x - y;                                                                          //Doing subtraction
        printf(" Subtraction: x - y = %lf",s);                                              // Printing subtraction
    }
    else if ( ope == '*')                                                                   //to check operator entered from user whether it is * or not
    {
        s = x * y;                                                                          //Doing Multiplication
        printf(" Multiplication: x * y = %lf",s);                                           // Printing multiplication
    }
    else if ( ope == '/')                                                                   //to check operator entered from user whether it is / or not
    {
        s = x / y;                                                                          // Doing Division
        printf(" Division: x \\ y = %lf",s);                                                // Printing Division
    }
    else if ( ope == '%')                                                                   //to check operator entered from user whether it is % or not
    {
        r = (int)x % (int)y;                                                                // Here first both number is type-casted in integer from decimal because modulus operator is used only in integer
        printf(" Remainder: x %% y = %d",r);                                                // Printing Remainder
    }
    else if ( ope == 'L')
    {
        printf("LCM: %d\n", lcm(x, y));
    }
    else if (ope == 'H')
    {
        printf("GCD: %d\n", gcd(x, y));
    }
    else
        printf(" Wrong Algebraic operator entered\n Please Enter Algebraic operator as mentioned above");
    return 0;
}
