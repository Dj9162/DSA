#include <iostream>
using namespace std;
int binarysearch(int arr[], int n, int key)
{
    int e = 0;
    int s = n;
    while (e <= s)
    {
        int mid = (s + e) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            e = mid + 1;
        }
        else
        {
            s = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, key;
    cout << "Enter number of places in array:" << endl;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter values of array: " << endl;
        cin >> array[i];
    }
    cout << "Enter value which you want to search: " << endl;
    cin >> key;
    cout << binarysearch(array, n, key) << " is the place of your given value in the array" << endl;
    return 0;
}