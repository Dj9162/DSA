#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int l,int n)
{
    for (int i = l; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Merge(int arr[],int p,int m,int q)
{
    int n = m-p+1;
    int o = q-m;
    int L[n],R[o];
    for(int a = 0; a< n; a++)
    {
        L[a] = arr[p+a];
    }
    for(int b = 0; b < o; b++)
        R[b] = arr[m+b+1];

    int i = 0,j = 0,k = p;
    while(i < n && j < o)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while( j < o)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void Merge_sort(int arr[],int l, int h)
{
    if(l >= h)
        return;
    int m = l +(h-l)/2;
    if(l+m <= 3)
        selection_sort(arr,l,m);
    if(m+h+1 <= 3)
        selection_sort(arr,m+1,h);
    else
    {
        Merge_sort(arr,l,m);
        Merge_sort(arr,m+1,h);
    }
    Merge(arr,l,m,h);
}
int main()
{
    int arr[] = {2,8,5,9,4,45,7,1,63,45,89,10};
    Merge_sort(arr,0,11);
    for(int i = 0; i < 12; i++)
        cout << arr[i] << " ";
    return 0;
}