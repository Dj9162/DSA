#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter Value of N? ";
    cin >> n;
    int a = 0, b = 1;
    bool even = false;
    for(int i = 0; i < n; i++){
        int c = a + b;
        if(!even)
        {
            cout << -c;
            for(int i = 0; i < c; i++)
                cout << "-";
            cout << "\n";
            even = true;
        }
        else{
            
            for(int i = 0; i < c; i++)
                cout << "*";
            cout << c << "\n";
            even = false;
        }
        a = b;
        b = c;
    }
    cout << "Enter any recurrence formula." << "\n";
    int m;
    cout << "Enter how many previous values are considered (upto 3)? ";
    cin >> m;
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0,v1 = 0, v2 = 0, v3 = 0;
    cout << "Enter constant coefficient." << "\n";
    cout << "Constant Coef: ";
    cin >> x4;
    for(int i = 0; i < m; i++){
        cout << "Enter coefficient and Enter value of x_" << i+1 << "\n";
        if(i == 0){
            cout << "First coef, value: ";
            cin >> x1 >> v1;
        } 
        else if(i == 1){
            cout << "Second coef, value: ";
            cin >> x2 >> v2;
        }
        else{
            cout << "Third coef, value: ";
            cin >> x3 >> v3;
        }
        cout << "\n\n";
    }
    cout << "The entered recurrence relation is: x_n = ";
    if(x1){
        cout << x1 << "*x_n-1 + ";
    }
    if(x2){

        cout << x2 << "*x_n-2 + ";
    }
    if(x3){
        cout << x3 << "*x_n-3 + ";
    }
    if(x4){
        cout << x4 << "." << "\n";
    }
    cout << "\n";
    cout << "Enter Value of N?";
    cin >>n;
    for(int i = 1; i <= n; i++){
        int c = x1 * v1 + x2 * v2 + x3 * v3 + x4;
        if(i == 1){
            cout << i+2 << "rd Number: " << c << "\n";
        }
        else
            cout << i+2 << "th Number: " << c << "\n";
        if(m == 1)
            v1 = c;
        else if(m == 2){
            v1 = v2;
            v2 = c;
        }
        else{
            v1 = v2;
            v2 = v3;
            v3 = c;
        }
    }

    return 0;
}