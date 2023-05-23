//Method:1   (LINEAR SEARCH)    Time Complexity: O(n)

//#include<bits/stdc++.h>
//using namespace std;
//int linear_search(int arr[],int n)
//{
//    for (int i=0;i<n ;i++ )
//    {
//        if (arr[i]==i)
//            return i;
//    }
//    return -1;
//}
//int main()
//{
//    int n;
//    int arr[]={-7,-1,0,3,6,8};
//    n=sizeof(arr)/sizeof(arr[0]);
//    cout<<linear_search(arr,n);
//    return 0;
//}

//Method:2    (BINARY SEARCH)    Time complexity: O(log n )

#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int low,int high)
{
    int mid=(low+high)/2;
    if (arr[mid]==mid)
        return mid;
    else if (arr[mid]>mid)
        return binary_search(arr,low,mid-1);
    else
        return binary_search(arr,mid+1,high);
    return -1;
}
int main()
{
    int n;
    int arr[]={-7,-1,0,3,6,8};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<binary_search(arr,0,n-1);
    return 0;
}
