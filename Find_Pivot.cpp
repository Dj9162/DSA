#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1, ans = -1;
    int m = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[m] > arr[m-1])
            s = m + 1;
        else
        {
            ans = arr[m];
            e = m;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v = {8,10,12,2,4,6};
    cout << pivot(v) << endl;
    return 0;
}