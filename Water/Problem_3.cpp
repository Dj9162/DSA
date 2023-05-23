// DHANRAJ KUMAR       ||       20CE10021       ||      PROBLEM - 3

#include <bits/stdc++.h>
using namespace std;


double F(double S, double n, double Q, double y, int b, int m){ // To calculate the function F
    double A = (b + m * y) * y;
    double Pw = b + 2 * y * sqrt(1 + m * m);
    double T = b + 2 * m * y;

    double f = (S - n * n * Q * Q * (pow(Pw, 1.333) / pow(A, 3.333))) / (1 - ((Q * Q * T)/ (9.81 * pow(A, 3))) );

    return f;
}

int main()
{
    int L = 4000, b = 5, m = 1;             // All the given values
    double S = 0.001, n = 0.025, Q = 40.5;
    cout << "Trapezoidal shape :-" << endl; // For Trapezoidal shape

    double yn = 2.84;

    double x = 1, yd = 1.5 * yn, y1 = yn, y2 = 0;
    double temp = yd;
    int q = 4000;

    while(q--){     // Applying Second Order Runge-Kutta method to calculate depth of water for Trapezoidal shape
        yd = temp;
        y2 = yd + 0.5 * F(S, n, Q, yd, b, m) * x;
        

        y1 = yd + F(S, n, Q, y2, b, m) * x;
        
        temp = y1;
        cout << y1 << endl;
    }


    return 0;
}