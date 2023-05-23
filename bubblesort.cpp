/* 12,4,56,33,67,8::4,8,12,33,56,67
In this sorting one element is compared with successive element and
if successive element is less than preceding element then we swap them
   12,4,56,33,67,8
   4,12,56,33,67,8
   4,12,56,33,67,8
   4,12,33,56,67,8
   4,12,33,56,67,8
   4,12,33,56,8,67
   4,12,33,56,8,67
   4,12,33,56,8,67
   4,12,33,56,8,67
   4,12,33,8,56,67
   4,12,33,8,56,67
   4,12,33,8,56,67
   4,12,33,8,56,67
   4,12,8,33,56,67
   4,12,8,33,56,67
   4,12,8,33,56,67
   4,12,8,33,56,67
   4,8,12,33,56,67 */
#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int c = 0;
    while (c <= n)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        c++;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}