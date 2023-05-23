#include <iostream>
using namespace std;
void rot_arr(int arr[], int n)
{
    
        for (int i = 0; i < n - 3 ; i+=2)
        {
            int temp = arr[i];
            int t = arr[i+1];
            arr[i] = arr[i + 2];
            arr[i+1] = arr[i+3];
            arr[i + 2] = temp;
            arr[i + 3] = t;
        }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int arr[6] = {1, 2, 3,4,5,6};
    rot_arr(arr, 6);
    return 0;
}