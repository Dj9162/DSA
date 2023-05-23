#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int main()
{
    vector<int> adj[N];
    int cnt = 0;
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n,0);
    int x, y;
    for(int i = 1; i <m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    for(int i = 1; i <n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        cnt++;
        int v = q.front();
        cout << v << " ";
        q.pop();
        for(auto it : adj[v])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    return 0;
}