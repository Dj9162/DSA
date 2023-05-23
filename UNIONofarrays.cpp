#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //Taking total number of places in arrays.
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m]; //deffining arrays
    //Taking inputs of arrays from user.
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> arr2[j];
    }
    int i = 0, j = 0; //Above i and j are only for "for" loop and these are different
    while (i < n && j < m)
    { //from this loop we printed all values of array till lesser places of arrays.
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j++];
        }
        else if (arr1[i] == arr2[j])
        {
            cout << arr2[j++];
            i++;
        }
    }
    //The below loops are to print all left values of both arrays.
    while (i < n)
    {
        cout << arr1[i++];
    }
    while (j < m)
    {
        cout << arr2[j++];
    }

    return 0;
}