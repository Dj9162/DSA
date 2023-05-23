#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1 = 0,n2 = 0;
    cout << "Enter First 2 numbers: ";
    cin >> n1 >> n2;
    int a = 1;
    bool common = true;
    cout << "Common prime numbers that divides the first two numbers are:" << "\n";
    while(1){
        int smaller = n1, gcd = 1;
        if( n1 > n2)
            smaller = n2;
        
        for(int i = 2; i <= smaller; i++){
            bool prime = true;
            for(int j = 2; j <= i; j++){
                if(i % j == 0 && j == i && prime)
                    prime = true;
                else if(i % j == 0)
                    prime = false;
            }
            if(prime){
                if( n1 % i == 0 && n2 % i == 0){
                    gcd *= i;
                    if(common)
                        cout << i << "\n";
                }
            }
        }
        cout << "The GCD up to now is: " << gcd << "\n";
        if(common)
            cout << "The LCM of the first two numbers is: " << (n1 * n2)/gcd << "\n";
        common = false;
        cout << "Enter next number: ";
        cin >> a;
        if(a == 0 || a == -1)
            break;
        n1 = gcd;
        n2 = a;
    }
    return 0;
}