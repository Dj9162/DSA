//Method:1  Time Complexity: O(n^2)

#include<iostream>
using namespace std;
void maj_element(int arr[],int n)
{
    int x=0,temp;
    for (int i=0;i<n ;i++ )//It choose an element first then
    {
        int y=0;//to initialize y to count how many times majority element repeats.
        for (int j=0;j<n ;j++ )//It chooses all other element to compare with previously chosen element
        {
            if (arr[j]==arr[i])//it compares both element
            {
                y++;
                if (y>x)
                {
                    x=y;
                    temp=arr[j];
                }
            }
        }
    }
    if (x>=n/2)//maximum one element can repeat to be a major element is to repeat more than half of total length of array
    {
        cout<<temp;
    }
    else
    {
        cout<<"Not exist";
    }
}
//Directive program to test above function
int main()
{
    int n;
    int arr[]={3,4,2,4,2,3,2,4,2,1,2,8,2,4,2,6,2,8,2,2,0,2,2,2};
    n=sizeof(arr)/sizeof(arr[0]);//This is to determine the length of an array.
    maj_element(arr,n);
    return 0;
}
//=========================================================================================

//Method:2  Time Complexity:O(n)

#include<iostream>
using namespace std;
//function to find the candidate for majority
int find_cand(int arr[],int n)        //This function is based on that if an element is a majority element in an array
{                                     //then it must be written side by side at least one time
    int count=1,max_element=0;        //and after that if there is another element then after that same element will occur
    for (int i=1;i<n ;i++ )
    {
        if (arr[max_element]==arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count==0)
        {
            max_element=i;
            count=1;
        }
    }
    return arr[max_element];
}
//function to check if the candidate occurs more than n/2 times
bool maj_element(int arr[],int n,int x)
{
    int count=0;
    for (int i=0;i<n ;i++ )
    {
        if (arr[i]==x)//It compares element
        {
            count++;
        }
    }
        if (count>n/2)//It count that element is a majority element or not
        {
            return 1;
        }
        else
        {
            return 0;
        }
}
void print_maj_element(int arr[],int n)
{
    int x=find_cand(arr,n);
    if (maj_element(arr,n,x))
    {
        cout<<x;
    }
    else
    {
        cout<<"NOT FOUND";
    }
}
int main()
{
    int n;
    int arr[]={5,3,5,5,4,5,2,5};
    n=sizeof(arr)/sizeof(arr[0]);
    print_maj_element(arr,n);
    return 0;

}

