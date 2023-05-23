#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
vector<int> parent(N);
void make_set(int v)  // making set of each element and parent of each set itself
{
    parent[v] = v;
}

// int find_set(int v)  // To find parent of any set || Time Complexcity = O(n)
// {
//     if(parent[v] == v)
//         return v;
//     return find_set(parent[v]);
// }

int find_set(int v) // Path compression method || Time Complexicty = O(logn) 
{
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);

}

void Union(int x, int y)  // Making union of two sets by making parent of x equal to  parent of y
{
    int a = find_set(x);
    int b = find_set(y);
    if(a == b)
        return;
    parent[b] = a;
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
    return 0;
}