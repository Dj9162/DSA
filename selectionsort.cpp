 /*12,33,76,56,46,8 :: 8,12,33,46,56,76
In this sorting we take one element and compare it with all other element after that
and if other element is less than the taken element then we swap them.
12,33,76,56,46,8
8,33,76,56,46,12
8,12,76,56,46,33
8,12,56,76,46,33
8,12,46,76,56,33
8,12,33,76,56,46
8,12,33,56,76,46
8,12,33,46,76,56
8,12,33,46,56,76*/
#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cout << "Enter number of places in array: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}