#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n>>m;
    vector<bool> vis(n,false);
    vector<int> adj[n];
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    

    return 0;
}