/*Longest span with same sum in two binary arrays
Input: arr1[] = {0,1,0,1,1,1,1}
       arr2[] = {1,1,1,1,1,0,1}
output: 6
The Longest spam with same sum is from index 1 to 6.

************************************************************

*/

//Method: 1
//This method have O(n*n) time complexity.
// #include <iostream>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int n, max_span = 0;
//     cin >> n;
//     int arr1[n], arr2[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr1[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr2[i];
//     }
//     //one by one pick all possible starting points of subarrays.
//     for (int i = 0; i < n; i++)
//     {
//         //Initialize sums of current subarrays
//         int sum1 = 0, sum2 = 0,span=0;
//         for (int j = i; j < n; j++)
//         {
//             //at each steps update sums
//             sum1 += arr1[j];
//             sum2 += arr2[j];
//             //if sums are same and current lenght is more than max_len, update max_length
//             if (sum1 == sum2)
//             {
//                 span=j-i+1;
//                 if (span>max_span)
//                 {
//                     max_span=span;
//                 }

//             }
//         }
//     }
//     cout << max_span;

//     return 0;
// }

//***********************************************************************

// Method:2
//Time comeplexity: O(n)
#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, sum1 = 0, sum2 = 0, curr_diff, diff, len = 0, max_len = 0;
    cin >> n;
    int arr1[n], arr2[n], diff_arr[2 * n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < 2 * n + 1; i++)
    {
        diff_arr[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        sum1 += arr1[i];
        sum2 += arr2[i];
        curr_diff = sum1 - sum2;
        diff = n + curr_diff;
        if (curr_diff == 0)
        {
            max_len = i + 1;
        }
        else if (diff_arr[diff] == -1)
        {
            diff_arr[diff] = i;
        }
        else
        {
            len = i - diff_arr[diff];
            if (len > max_len)
            {
                max_len = len;
            }
        }
    }
    cout<<max_len;


    return 0;
}