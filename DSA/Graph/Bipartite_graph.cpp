#include <bits/stdc++.h>
using namespace std;

void color(int src,vector<vector<int>> &adj, vector<bool> &vis,vector<int> &col, bool &bipartite,int curr)
{
    if( col[src] != -1 and col[src] != curr)
    {
        bipartite = false;
        return;
    }
    col[src] = curr;
    if(vis[src])
        return;
    vis[src] = true;
    for(auto i: adj[src])
    {
        color(i,adj,vis,col,bipartite,curr xor 1);
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1,false);
    vector<int> col(n+1,-1);
    int x,y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool bipartite = true;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            color(i,adj,vis,col,bipartite,0);
    }
    if(bipartite)
        cout << "Bipartite graph" << endl;
    else
        cout << "Not Bipartite graph" << endl;
    return 0;
}
