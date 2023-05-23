/*
//Method: 1  with Time Complexity: O(n^2)

#include<iostream>
using namespace std;
int leader(int arr[],int n)
{
    int max_arr=arr[n-1];
    for (int i=0;i<n ;i++ )
    {
        int j;
        for (int j=i+1;j<n ;j++ )
        {
            if (arr[i]<arr[j])
            {
                break;
            }
            else
            {
                max_arr=max(max_arr,arr[i]);
            }
        }
    }
    return max_arr;
}
int main()
{
    int arr[]={16,17,4,37,25,232};
    cout<<leader(arr,6);
    return 0;
}
*/

//====================================================================================

//Method:2  with Time Complexity: O(n)

#include<iostream>
using namespace std;
int leader(int arr[],int n)
{
    int max_leader=arr[n-1];
    for (int i=n-2;i>=0 ;i-- )
    {
        if (arr[i]>max_leader)
        {
           max_leader=arr[i];
        }
    }
    return max_leader;
}
int main()
{
    int arr[]={116,17,4,3,35,72};
    cout<<leader(arr,6);
    return 0;
}
