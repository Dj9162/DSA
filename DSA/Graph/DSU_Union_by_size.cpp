#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
vector<int>size(N);
vector<int> parent(N);

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v)
{
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Union(int x, int y)
{
    int a = find_set(x);
    int b = find_set(y);
    if(a == b)
        return;
    else if(size[a] < size[b])
        swap(a,b);
    parent[b] = a;
    size[a] += size[b];
}
int main()
{
    for(int i = 0; i < 6; i++)
        make_set(i);

    cout << find_set(5) << endl;
    Union(1,2);
    Union(3,4);
    Union(2,5);
    cout << find_set(5) << endl;
    cout << size[1] << endl;
    return 0;
}