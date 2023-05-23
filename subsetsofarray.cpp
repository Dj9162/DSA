// To print all the subsets of an array
/*
    arr = {1,2,3}
    All permutations and combinations of above array:
    0 0 0 = _ _ _
    0 0 1 = _ _ 3
    0 1 0 = _ 2 _
    0 1 1 = _ 2 3
    1 0 0 = 1 _ _
    1 0 1 = 1 _ 3
    1 1 0 = 1 2 _
    1 1 1 = 1 2 3
*/
#include <iostream>
using namespace std;
void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ( i & (1 << j))
            {
                cout << arr[j] << " ";
            }
            
        }
        cout << endl;
        
    }
    
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    subsets(arr, 5);
    return 0;
}