#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    int maxIdx = i;
    int l = 2*i +1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[maxIdx])
        maxIdx = l;
    if(r < n && a[r] > a[maxIdx])
        maxIdx = r;
    if(maxIdx != i)
    {
        swap(a[i],a[maxIdx]);
        heapify(a,n,maxIdx);
    }
}

void heapsort(vector<int> &a)   // function to sort an array
{
    int n = a.size();
    for(int i = 0; i < n/2 ; i++)
        heapify(a,n,i);             // first of all convert the given array into min heap or max heap as you wish
    for(int i = n-1; i >0 ; i--)    // now swap first and last element and decrease size of heap by 1 and heapify them
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    heapsort(a);
    for(int i = 0; i < n ; i++)
    cout << a[i] << " ";
    return 0;
}