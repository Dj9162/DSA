#include<stdio.h>
void segregate(int arr[], int n)
{
    int left=0,right=n-1;
    while(left< right)
    {
        while(left<right && arr[left]==0)
            left++;
        while(left < right && arr[right]==1)
            right--;
        if (left<right)
        {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;

        }
    }
}
int main()
{
    int arr[]={1,0,1,0,0,1,1,1,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    segregate(arr, n);
    for (int i=0;i<n ;i++ )
        printf("%d",arr[i]);
    return 0;
}
