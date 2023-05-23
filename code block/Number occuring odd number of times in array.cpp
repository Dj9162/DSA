////Method:1       Time Complexity: O(n)
//
//#include<iostream>
//using namespace std;
//int odd_occur(int arr[],int n)
//{
//    int res=0;               // XOR = A^A =0
//    for (int i=0;i<n ;i++ )  // XOR = A^A^A =A
//    {
//        res=res^arr[i];
//    }
//    return res;
//}
//int main()
//{
//    int n;
//    int arr[]={1,2,3,2,3,1,3};
//    n=sizeof(arr)/sizeof(arr[0]);
//    cout<<"Number occurring odd number of times is: "<<odd_occur(arr,n);
//    return 0;
//}

//Method:2       Time Complexity: O(n*n)

#include<iostream>
using namespace std;
int odd_occur(int arr[],int n)
{
    int odd=0;
    for (int i=0;i<n ;i++ )
    {
        int count=0;
        for (int j=0;j<n ;j++ )
        {
            if (arr[i]==arr[j])
            {
                count++;
            }
        }
        if (count%2!=0)
        {
            return arr[i];
        }
    }
}
int main()
{
    int n;
    int arr[]={1,2,1,2,3,2,3};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Number occurring odd number of times in array: "<<odd_occur(arr,n);
    return 0;
}
