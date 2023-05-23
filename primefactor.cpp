#include <iostream>
using namespace std;
void primefac(int n)
{
    /* In this first we initialize all the places of array with own value*/
    int spf[100] = {0};
    for(int i=2; i<=n; i++)
    {
        spf[i] = i;
    }
    // Now, Initialize all number of places with its smallest prime factor
    for(int i=2; i<=n; i++)
    {
        if ( spf[i] ==i)
        {
            for(int j= i*i; j<=n; j+=i)
            {
                if (spf[j] == j)
                {
                    spf[j] =i;
                }
            }
                
        }
        
    }
    // Divide the given number with its spf and print and change number to new number which we got
    while (n!=1)
    {
        cout << spf[n] << " ";
        n = n /spf[n];
    }
    
    
}
int main()
{
    int n;
    cin >> n;
    primefac(n);
    return 0;
}