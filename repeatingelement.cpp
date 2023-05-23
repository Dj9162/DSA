//This is for timecomplexity: O(n*n)

// #include <iostream>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 cout << i;
//                 goto end;
//             }
//         }
//     }
// end:

//     return 0;
// }

//This is for Timecomplexity: O(n)
// #include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    const int N = 1000;
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }
    int minidx = 1000;
    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]] = i;
        }
    }
    if (minidx == 1000)
    {
        cout << "No repeatition" << endl;
    }
    else
    {
        cout << minidx + 1 << endl;
    }

    return 0;
}