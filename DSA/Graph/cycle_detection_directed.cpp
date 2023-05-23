#include <bits/stdc++.h>
using namespace std;

iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[src] = true;
    if(!visited[src])
    {
        visited[src] = true;
        for(auto i: adj[src])
        {
            if(!visited[i] and iscycle(i,adj,visited,stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[src] = false;
    return false;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> stack(n,0);
    vector<bool> visited(n,0);

    int x, y;
    for(int i = 1; i < m ; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    bool cycle = false;

    for(int i =1; i < n; i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,stack))
            cycle = true;
    }

    if(cycle)
        cout << "Cycle Found!!" << endl;
    else
        cout << "Cycle not Found!!" << endl;

    return 0;
}