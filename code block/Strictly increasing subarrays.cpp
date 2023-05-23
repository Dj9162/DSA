/* Input: arr[]= {1,2,3,4}
   Output: 6
   There are 6 sub arrays {1,2}, {1,2,3}, {1,2,3,4}, {2,3}, {2,3,4} and {3,4}
*/

//================================================================================================================

//Method:1  (Simple Solution)  Time Complexity:O(m) where m is number of sub arrays in output.

//#include<bits/stdc++.h>
//using namespace std;
//int func(int arr[],int n)
//{
//    int cnt=0;
//    for (int i=0;i<n ;i++ )
//    {
//        for (int j=i+1;j<n ;j++ )
//        {
//            if (arr[j]>arr[j-1])
//                cnt++;
//            else
//                break;
//        }
//    }
//    return cnt;
//}
//int main()
//{
//    int n;
//    int arr[]={1,2,3,4};
//    n=sizeof(arr)/sizeof(arr[0]);
//    cout<<func(arr,n);
//    return 0;
//}

//===========================================================================================================================

//Method:2  (Efficient Solution)  Time Complexity: O(n) where n is number of element in array.

#include<bits/stdc++.h>
using namespace std;
int func(int arr[],int n)
{
    int len=1,cnt=0;
    for (int i=0;i<n ;i++ )
    {
        if (arr[i+1]>arr[i])
            len++;
        else
        {
            cnt+=len*(len-1)/2;//In a sorted array there are total [n*(n-1)/2] strictly increasing sub arrays.
            len=1;
        }
    }
    if (len>1)
        cnt+=len*(len-1)/2;
    return cnt;
}
int main()
{
    int n;
    int arr[]={1,2,3,4};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<func(arr,n);
    return 0;
}
