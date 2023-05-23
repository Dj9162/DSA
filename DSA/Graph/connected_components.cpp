#include <bits/stdc++.h>
using namespace std;

int con_com(int src,vector<vector<int>> &adj,vector<bool> &vis,int cnt)
{

    vis[src] = true;
    for(auto i : adj[src])
    {
        if(!vis[i])
        {
            cnt++;
            return con_com(i,adj,vis,cnt);
        }
    }
    return cnt;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);
    vector<int> components;
    int x,y;
    for(int i = 1; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i < n; i++ )
    {
        if(!vis[i])
           components.push_back(con_com(i,adj,vis,1));
    }
    int ans = 0;
    for(int i = 0; i < components.size(); i++)
        ans += components[i]*(n-components[i] -1);
    
    cout << ans/2 << endl;

    return 0;
}