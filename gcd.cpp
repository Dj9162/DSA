// Using Euclid theorem to find gcd of two numbers
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    // According to Euclid theorem, gcd of two numbers is same if gcd is calculated between number and their difference
    // Here instead of difference i used remainder of two numbers
    while (b!=0)
    {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
    
}

int gc_d(int a, int b){
    // Finding GCD using Euclid theorem
    while(a != 0 && b != 0){
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    if(a == 0)
        return b;
    return a;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << gc_d(a,b);
    return 0;
}