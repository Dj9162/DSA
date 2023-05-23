#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int arr[8];
        cin >> arr[0] >> arr[1];
        cin >> arr[2] >> arr[3] >> arr[4] >> arr[5];
        cin >> arr[6] >> arr[7];
        float temp = INT_MAX;
        int f = 1;
        if((abs(arr[6]-arr[2]) + arr[4]) <=arr[0] )
            {temp = min(temp,(float)abs(arr[6]-arr[2])); f = 0;}
        if((abs(arr[7] - arr[3]) + arr[5]) <=arr[1])
            {temp = min(temp,(float)abs(arr[7] - arr[3])); f = 0;}
        
        if(f == 1)
            cout << "-1" << endl;
        else
            printf("%0.9f\n",temp);
    }
    
    return 0;
}