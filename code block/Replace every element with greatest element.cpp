//Method:1  (NATIVE METHOD)  Time Complexity:O(n*n)

//#include<iostream>
//using namespace std;
//void great_element(int arr[],int n)
//{
//    for (int i=0;i<=n-2 ;i++ )
//    {
//        int max_ele=arr[n-1];
//        for (int j=i+1;j<n ;j++ )
//            max_ele=max(max_ele,arr[j]);
//        arr[i]=max_ele;
//    }
//    arr[n-1]=-1;
//    for (int i=0;i<n ;i++ )
//        cout<<arr[i]<<" ";
//}
//int main()
//{
//    int n;
//    int arr[]={16,17,4,6,3,5,3,5,7,3,6,8,2,6,8,3,5,7,4,5,7,6,4,4,3,2,1,0};
//    n=sizeof(arr)/sizeof(arr[0]);
//    great_element(arr,n);
//    return 0;
//}

//Method:2  (TRICKY)  Time Complexity: O(n)

#include<iostream>
using namespace std;
void great_element(int arr[],int n)
{
    int max_ele=arr[n-1];
    arr[n-1]=-1;

    for (int i=n-2;i>=0 ;i-- )
    {
        int temp=arr[i];
        arr[i]=max_ele;
        if (max_ele<temp)
            max_ele=temp;
    }
    for (int i=0;i<n ;i++ )
        cout<<arr[i]<<" ";
}
int main()
{
    int n;
    int arr[]={16,17,4,6,3,5,3,5,7,3,6,8,2,6,8,3,5,7,4,5,7,6,4,4,3,2,1,0};
    n=sizeof(arr)/sizeof(arr[0]);
    great_element(arr,n);
    return 0;
}
