#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int low,int high, int n)
{
    int mid=low+(high -low)/2;
    if ((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
        return mid;
    else if(mid>0 && arr[mid-1] > arr[mid])
        return binary(arr,low,(mid-1),n);
    else
        return binary(arr,(mid+1),high,n);
}
int findpeak(int arr[],int n)
{
    return binary(arr,0,n-1,n);
}
int main()
{
    int n;
    int arr[]={1,3,20,4,1,0,10,90,6};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<findpeak(arr,n)<<" ";
    return 0;
}
