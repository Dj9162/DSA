//                          CE39204 WATER RESOURCES AND GEOTECHNICAL ENGINEERING SESSIONAL
// DHANRAJ KUMAR       ||       20CE10021       ||      PROBLEM - 2

#include <bits/stdc++.h>
using namespace std;

double Fn(int b, int m, int Q, double yn){  // Function to calculate fn function to calculate normal depth
    double S = 0.001, n = 0.025;
    double temp1 = (b + m * yn) * yn, temp2 = b + 2 * yn * pow((1 + m),0.5);

    double f = (((pow(S, 0.5))/n) * ((pow(temp1, (5.0/3)))/ (pow(temp2, (2.0/3))))) - Q;

    return f;
}

double Fn1(int b, int m, double yn){        // To differentiate fn function
    double S = 0.001, n = 0.025;
    double temp1 = (b + m * yn) * yn, temp2 = b + 2 * yn * pow((1 + m),0.5);
    double f1 = ((pow(S, 0.5)) * (pow(temp1, (2.0/3))) *  (sqrt(1+m*m) * (10 * yn * yn * m + 6 * b * yn) + 10 * b * yn * m + 5 * b * b)) / (3 * n * pow(temp2, (5.0/3)));
    return f1;
}

double Fc(int b, int m, double yc, int Q){  // Function to calculate fc function to calculate critical depth
    double temp1 = (b + m*yc) * yc;
    double temp2 = b + 2 *m* yc;

    double f = ((pow(temp1, (3.0/2)) / (pow(temp2, 0.5))) - (Q / pow(9.81, 0.5)));

    return f;
}

double Fc1(int b, int m, double yc){    // To differntiate fc function
    double temp1 = (b + m*yc) * yc;
    double temp2 = b + 2 *m* yc;

    double f1 = -1 * ((pow(temp1, (3.0/2)) / (pow(temp2, (3.0/2)))))  + (3.0/2) * (pow((temp1 * temp2), 0.5));

    return f1;
}

int main()
{
    // For Trapezoidal shape
    int L = 4000, Q = 26, b = 5, m = 1;
    cout << "For Trapezoidal shape :-" << endl;

    double y1 = 2,yn = 3, temp = 3;
    
    while(abs(y1 - yn) > 0.001){        // Applying Newton-Raphson iterative algorithm to calculate normal depth for Trapezoidal shape
        
        yn = temp;
        // cout << yn << y1 << endl;
        double f = Fn(b,m,Q,yn);
        // cout << "fn = " << f;
        double f1 = Fn1(b,m,yn);
        // cout << "f1 = " << f1 << endl;
        y1 = yn - (f / f1);
        
        temp = y1;
    }
    cout << "Normal depth = "<< yn << endl;

    double y2 = 3, yc = 1;
    temp = 2;
    while(abs(y2 - yc) > 0.001){    // Applying Newton-Raphson iterative algorithm to calculate critical depth for Trapezoidal shape
        yc = temp;
        
        double f = Fc(b,m,yc,Q);
        double f1 = Fc1(b,m,yc);
    
        y2 = yc - (f/f1);
        temp = y2;
    }
    cout << "Critical depth = " << yc << endl;

    // For Rectangular shape
    cout << "For Rectangular shape :-" << endl;

    b = 5, m = 0;
    y1 = 2,yn = 3, temp = 3;
    
    while(abs(y1 - yn) > 0.001){    // Applying Newton-Raphson iterative algorithm to calculate normal depth for Rectangular shape
        
        yn = temp;
        
        double f = Fn(b,m,Q,yn);
        double f1 = Fn1(b,m,yn);
        y1 = yn - (f / f1);
        temp = y1;
    }
    cout << "Normal depth = "<< yn << endl;

    y2 = 3, yc = 1;
    temp = 2;
    while(abs(y2 - yc) > 0.001){    // Applying Newton-Raphson iterative algorithm to calculate critical depth for Rectangular shape
        yc = temp;
        
        double f = Fc(b,m,yc,Q);
        double f1 = Fc1(b,m,yc);
    
        y2 = yc - (f/f1);
        temp = y2;
    }
    cout << "Critical depth = " << yc << endl;

    // For Triangular shape
    cout << "For Triangular shape :-" << endl;

    b = 0, m = 1;
    y1 = 2,yn = 3, temp = 3;
    
    while(abs(y1 - yn) > 0.001){    // Applying Newton-Raphson iterative algorithm to calculate normal depth for Triangular shape
        
        yn = temp;
        double f = Fn(b,m,Q,yn);
        double f1 = Fn1(b,m,yn);
        y1 = yn - (f / f1);
        temp = y1;
    }
    cout << "Normal depth = "<< yn << endl;

    y2 = 3, yc = 1;
    temp = 2;
    while(abs(y2 - yc) > 0.001){    // Applying Newton-Raphson iterative algorithm to calculate critical depth for Triangular shape
        yc = temp;
        cout << yc << " " << y2 << endl;
        
        double f = Fc(b,m,yc,Q);
        double f1 = Fc1(b,m,yc);
    
        y2 = yc - (f/f1);
        temp = y2;
    }
    cout << "Critical depth = " << yc << endl;

    return 0;
}
