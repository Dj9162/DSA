// DHANRAJ KUMAR       ||       20CE10021       ||      PROBLEM - 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For Trapezoidal shape
    int L = 4000, b = 5, m = 1;
    double S = 0.001, n = 0.025, Q = 26;
    cout << "Trapezoidal shape :-" << endl;

    double y = 2,yn = 3, temp = 3;
    
    cout << "Normal depth = "<< yn << endl;
    while(abs(y - yn) > 0.001){     
        
        yn = temp;
        cout << yn << " " << y << endl;
        double temp1 = (b + m * yn) * yn, temp2 = b + 2 * yn * pow((1 + m),0.5);

        double f = (((pow(S, 0.5))/n) * ((pow(temp1, (5.0/3)))/ (pow(temp2, (2.0/3))))) - Q;
        double f1 = ((pow(S, 0.5)) * (pow(temp1, (2.0/3))) *  (sqrt(1+m*m) * (10 * yn * yn * m + 6 * b * yn) + 10 * b * yn * m + 5 * b * b)) / (3 * n * pow(temp2, (5.0/3)));
        y = yn - (f / f1);
        
        temp = y;
    }

    double x = 3, yc = 1;
    cout << "Critical depth = " << yc << endl;
    temp = 2;
    while(abs(x - yc) > 0.001){
        yc = temp;
        cout << yc << " " << x << endl;
        double temp1 = (b + m*yc) * yc;
        double temp2 = b + 2 *m* yc;
        double f = ((pow(temp1, (3.0/2)) / (pow(temp2, 0.5))) - (Q / pow(9.81, 0.5)));
        double f1 = -1 * ((pow(temp1, (3.0/2)) / (pow(temp2, (3.0/2)))))  + (3.0/2) * (pow((temp1 * temp2), 0.5));
    
        x = yc - (f/f1);
        temp = x;
    }

    // For Rectangular shape
    cout << "Rectangular shape :-" << endl;

    b = 5, m = 0;
    y = 2,yn = 3, temp = 3;
    
    cout << "Normal depth = "<< yn << endl;
   while(abs(y - yn) > 0.001){
        
        yn = temp;
        cout << yn << " " << y << endl;
        double temp1 = (b + m * yn) * yn, temp2 = b + 2 * yn * pow((1 + m),0.5);

        double f = (((pow(S, 0.5))/n) * ((pow(temp1, (5.0/3)))/ (pow(temp2, (2.0/3))))) - Q;
        double f1 = ((pow(S, 0.5)) * (pow(temp1, (2.0/3))) *  (sqrt(1+m*m) * (10 * yn * yn * m + 6 * b * yn) + 10 * b * yn * m + 5 * b * b)) / (3 * n * pow(temp2, (5.0/3)));
        y = yn - (f / f1);
        
        temp = y;
    }

    x = 3, yc = 1;
    temp = 2;
    cout << "Critical depth = " << yc << endl;
    while(abs(x - yc) > 0.001){
        yc = temp;
        cout << yc << " " << x << endl;
        double temp1 = (b + m*yc) * yc;
        double temp2 = b + 2 *m* yc;
        double f = ((pow(temp1, (3.0/2)) / (pow(temp2, 0.5))) - (Q / pow(9.81, 0.5)));
        double f1 = -1 * ((pow(temp1, (3.0/2)) / (pow(temp2, (3.0/2)))))  + (3.0/2) * (pow((temp1 * temp2), 0.5));
    
        x = yc - (f/f1);
        temp = x;
    }

    // For Triangular shape
    cout << "Triangular shape :-" << endl;

    b = 0, m = 1;
    y = 2,yn = 3, temp = 3;
    
    cout << "Normal depth = "<< yn << endl;
    while(abs(y - yn) > 0.001){ 
        
        yn = temp;
        cout << yn << " " << y << endl;
        double temp1 = (b + m * yn) * yn, temp2 = b + 2 * yn * pow((1 + m),0.5);

        double f = (((pow(S, 0.5))/n) * ((pow(temp1, (5.0/3)))/ (pow(temp2, (2.0/3))))) - Q;
        double f1 = ((pow(S, 0.5)) * (pow(temp1, (2.0/3))) *  (sqrt(1+m*m) * (10 * yn * yn * m + 6 * b * yn) + 10 * b * yn * m + 5 * b * b)) / (3 * n * pow(temp2, (5.0/3)));
        y = yn - (f / f1);
        
        temp = y;
    }

    x = 3, yc = 1;
    temp = 2;
    cout << "Critical depth = " << yc << endl;
    while(abs(x - yc) > 0.001){ 
        yc = temp;
        cout << yc << " " << x << endl;
        double temp1 = (b + m*yc) * yc;
        double temp2 = b + 2 *m* yc;
        double f = ((pow(temp1, (3.0/2)) / (pow(temp2, 0.5))) - (Q / pow(9.81, 0.5)));
        double f1 = -1 * ((pow(temp1, (3.0/2)) / (pow(temp2, (3.0/2)))))  + (3.0/2) * (pow((temp1 * temp2), 0.5));
    
        x = yc - (f/f1);
        temp = x;
    }


    return 0;
}