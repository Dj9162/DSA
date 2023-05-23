#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cout << "Enter edge and weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> cost(n, INT_MAX), parent(n, -1) ;
    vector<bool> vis(n, false);

    cost[0] = 0;

    for(int i = 0; i < n; i++){

        // Finding minimum from cost array
        int mini = INT_MAX, u = 0;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && cost[v] < mini){
                mini = cost[v];
                u = v;
            }
        }
        vis[u] = true;

        // Finding adjacent nodes of u
        for(auto j: adj[u]){

            if( vis[j.first] == false && j.second < cost[j.first]){
                cost[j.first] = j.second;
                parent[j.first] = u;
            }
        }

    }

    int min_cost = accumulate(cost.begin(), cost.end(), 0);
    cout << "Cost of Minimum Spanning Tree is " << min_cost << endl;

    return 0;
}
