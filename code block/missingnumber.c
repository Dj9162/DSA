/*Method:1     Time complexity:O(n)
#include<stdio.h>
int mis_num(int arr[],int n)
{
    int sum=(n+1)*(n+2)/2;
    for (int i=0;i<n ;i++ )
        sum-=arr[i];
    return sum;
}
int main()
{
    int arr[]={1,2,3,5,6,7};
    printf("%d",mis_num(arr,6));
    return 0;
}
##include<stdio.h>
int main()
{

    return 0;
}*/
//In method 1-if the sum of the numbers goes beyond maximum allowed integer,then there can be integer overflow and we may not get correct answer
//Method-2   Time complexity-O(n)
// method 2 has no such problems.
#include<stdio.h>
//miss_number takes array and size of array as arguments
int miss_num(int arr[],int n)
{
    int xor1=arr[0];//for xor of all the elements in array
    int xor2=1;//For xor of all the elements from 1 to n+1
    for (int i=1;i<n ;i++ )
    {
        xor1=xor1^arr[i];
    }
    for (int i=2;i<=n+1 ;i++ )
    {
        xor2=xor2^i;
    }
    return xor1^xor2;
}
//program to test above function
int main()
{
    int arr[]={1,2,4,5,6};
    printf("%d",miss_num(arr,5));
    return 0;
}
