#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int odd[n],even[n];
        for(int i = 0; i < n; i++)
            cin >> odd[i];
        for(int i = 0; i < n; i++)
            cin >> even[i];
        int count;
        for(int i = 0; i < n; i++)
        {
            if(odd[i] < even[0])
            {    count = i; break;}
        }
        cout << count << endl;
    }
    return 0;
}