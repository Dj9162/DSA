//Method:1  Time Complexity:O(n^3)

//#include<bits/stdc++.h>
//using namespace std;
//bool pythagorean(int arr[],int n)
//{
//    for (int i=0;i<n ;i++ )
//    {
//        for (int j=i+1;j<n ;j++ )
//        {
//            for (int k=j+1;k<n ;k++ )
//            {
//                int x=arr[i]*arr[i],y=arr[j]*arr[j],z=arr[k]*arr[k];
//                if(x==y+z || y==x+z || z==x+y)
//                    return true;
//            }
//        }
//    }
//    return false;
//}
//int main()
//{
//    int n;
//    int arr[]={12,2,3,8,5,7,1,11,30,14};
//    n=sizeof(arr)/sizeof(arr[0]);
//    cout<<pythagorean(arr,n);
//    return 0;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Method:2   Time Complexity:O(n)

#include<bits/stdc++.h>
using namespace std;
void sort_arr(int arr[],int n)
{
    int c;
        while (c <= n)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        c++;
    }
}
bool pythagorean(int arr[],int n)
{
    int arr1[n];
    for (int i=0;i<n ;i++ )
    {
        arr1[i]=arr[i] *arr[i];
    }
    sort_arr(arr,n);
    for (int i=n-1;i>=2 ;i-- )
    {
        int l=0;
        int r=i-1;
        while(l<r)
        {
            if(arr1[l] +arr[r] == arr[i])
                return true;
            (arr1[l] +arr1[r] < arr[i])? l++: r--;
        }
    }
    return false;
}

int main()
{
    int n;
    int arr[]={1,5,3,6,9,4,7};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<pythagorean(arr,n);
    return 0;

}
