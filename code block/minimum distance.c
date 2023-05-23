//Method-1     Time complexity: O(n^2)
//******************************************
/*#include<stdio.h>
#include<limits.h>//This header file is included to use INT_MAX.
int min_distance(int arr[],int x,int y,int n)
{
    int dis=INT_MAX,min_dis=INT_MAX;
    for (int i=0;i<n ;i++ )
    {
        if (arr[i]==x || arr[i]==y)
        {
            for (int j=i+1;j<n ;j++ )
            {
                if (arr[j]==x && arr[j]!=arr[i] || arr[j]==y && arr[j] !=arr[i])
                {
                    dis=j-i;
                }
                if (dis<min_dis)
                {
                    min_dis=dis;
                }
            }
        }
    }
    if (min_dis==INT_MAX)
    {
        return -1;
    }
    else
    {
        return min_dis;
    }
}
//Driver program to test above function
int main()
{
    int arr[]={3,5,4,2,6,7,6,6,5,4,8,3};
    int n=min_distance(arr,3,9,12);
    printf("Minimum distance is %d",n);
    return 0;
}
*/
//*********************************************************************************************

//Method-2

#include<stdio.h>
#include<limits.h>
int mindis(int array[],int x,int y,int n)
{
    int prev,i=0;
    int min_distance=INT_MAX;
    for (i=0;i<n ;i++ )
    {
        if (array[i]==x || array[i]==y)
        {
            prev=i;
            break;
        }
    }
    for (;i<n ;i++ )
    {
        if (array[i]==x || array[i]==y )
        {
            if (array[prev] !=array[i] && (i-prev)<min_distance)
            {
                min_distance = i-prev;
                prev=i;
            }
            else
            {
                prev=i;
            }
        }
    }
    return min_distance;
}
int main()
{
    int array[]={3,5,4,2,8,7,6,6,5,4,8,3};
    printf("%d",mindis(array,3,8,12));
    return 0;
}
