// Program to print prime number using seive of Eranthosis
#include <iostream>
using namespace std;
void prime( int n)
{
    /* In this first we define an array and initialize that with 0 after that change value of places which is divisible by places whose square is less
       than given n number and print all numbers which value is not changed*/
    int arr[1000] = {0};
    for(int i=2 ; i<=n; i++)
    {
        if ( arr[i] == 0)
        {
            for(int j=i*i; j<=n; j+=i)
            {
                arr[j] = 1;
            }
        }
        
    }
    for( int i=2; i<=n; i++)
    {
        if (arr[i] == 0)
        {
            cout << i << " ";
        }
        
    }
}
int main()
{
    int n;
    cin >> n;
    prime(n);
    return 0;
}