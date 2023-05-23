#include <stdio.h>
#include <math.h>

int main()
{
    int L = 4000, b = 5, m = 1;
    double S = 0.001, n = 0.025, Q = 34;

    double yn = 2.6;

    int cycle = 4000;
    double delta_x = 1, Yd = 1.5 * yn, y = yn, yi = 0, A, Pw, T,f;
    double temp = Yd;

    while(cycle--){
        Yd = temp;
        A = (b + m * Yd) * Yd;
        Pw = b + 2 * Yd * sqrt(1 + m * m);
        T = b + 2 * m * Yd;

        f = (S - n * n * Q * Q * (pow(Pw, 1.333) / pow(A, 3.333))) / (1 - ((Q * Q * T)/ (9.81 * pow(A, 3))) );
        yi = Yd + 0.5 * f * delta_x;

        A = (b + m * yi) * yi;
        Pw = b + 2 * yi * sqrt(1 + m * m);
        T = b + 2 * m * yi;

        f = (S - n * n * Q * Q * (pow(Pw, 1.333) / pow(A, 3.333))) / (1 - ((Q * Q * T)/ (9.81 * pow(A, 3))) );
        y = Yd + f * delta_x;
        
        temp = y;
        printf("%lf\n", y);
    }


    return 0;
}