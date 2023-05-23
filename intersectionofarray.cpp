// #include <iostream>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int n, m;
//     cin >> n >> m;
//     int arr1[n], arr2[m];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr1[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin >> arr2[i];
//     }
//     if (n > m)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (arr1[i] == arr2[j])
//                 {
//                     cout << arr1[i] << " ";
//                 }
//             }
//         }
//     }
//     else
//     {
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (arr2[i] == arr1[j])
//                 {
//                     cout << arr2[i] << " ";
//                 }
//             }
//         }
//     }

//     return 0;
// }

//**********************************************************************************************************

//  Time complexity: O(n+m)

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else if (arr1[i] == arr2[j])
        {
            cout << arr1[i++]<<" ";
            j++;
        }
    }

    return 0;
}