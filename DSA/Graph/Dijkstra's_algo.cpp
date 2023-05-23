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
    int s;
    cout << "Enter starting point: ";
    cin >> s;

    vector<int> dis(n, INT_MAX), parent(n, -1);
    vector<bool> vis(n, false);

    dis[s] = 0;

    for(int i = 0; i < n; i++){

        int mini = INT_MAX, u = 0;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && dis[v] < mini){
                mini = dis[v];
                u = v;
            }
        }

        vis[u] = true;

        for(auto j: adj[u]){
            if(!vis[j.first] && j.second + dis[u] < dis[j.first]){
                dis[j.first] = dis[u] + j.second;
                parent[j.first] = u;
            }
        }

    }
    cout << "Minimum distance from starting node: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Distance from " << s << " to " << i << " is " << dis[i]<< endl;
    }


    return 0;
}
