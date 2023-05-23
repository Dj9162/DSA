////Method:1  Time Complexity:O(n)
//
//#include<bits/stdc++.h>
//using namespace std;
//void linear(int arr[],int n)
//{
//    for (int i=0;i<n ;i++ )
//    {
//        //If the element is first then compare it with only next element
//        if ((arr[i]==arr[0] || arr[i]>=arr[i-1]) && (arr[i]==arr[n-1] || arr[i]>=arr[i+1]))
//        //If the element is last then compare it with only previous element.
//        {
//            cout<<arr[i]<<" ";
//        }
//    }
//}
//int main()
//{
//    int n;
//    int arr[]={10,20,15,2,23,90,67};
//    n=sizeof(arr)/sizeof(arr[0]);
//    cout<<"Peak elements: ";//Peak elements are elements which are greater than both previous and next element.
//    linear(arr,n);
//    return 0;
//}

//=============================================================================================================================

//Method:2  [DIVIDE AND CONQUER(The idea is binary search based)] Time Complexity: O(log n)

#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int low,int high, int n)
{
    int mid=(low + high)/2;
    if ((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
        return arr[mid];
    else if(mid>0 && arr[mid-1] > arr[mid])
        return binary(arr,low,(mid+1),n);
    else
        return binary(arr,(mid-1),high,n);
}
int findpeak(int arr[],int n)
{
    return binary(arr,0,n-1,n);
}
int main()
{
    int n;
    int arr[]={10,20,15,2,23,90,67};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<findpeak(arr,n)<<" ";
    return 0;
}
