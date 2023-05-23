#include<bits/stdc++.h>
using namespace std;
#define N 100

//void DFS_Recursive(int node,vector<vector<int>> &adj, vector<bool> &vis)     // To check graph is right or wrong
//{
//    // preorder
//    vis[node] = 1;
//    cout << node << " ";
//
//    // Inorder
//    vector<int> :: iterator it;
//    for(it = adj[node].begin() ; it != adj[node].end() ; it++)
//    {
//        if(!vis[*it])
//        {
//            DFS_Recursive(*it,adj,vis);
//        }
//    }
//    // postorder
//    //cout << node << " ";
//}

int minDistance(int dist[], bool sptSet[],int m)  // Function to find minimum distance of vertex from another vertex which is not visited yet
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < m; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Solution(int dist[],int m,int src)  // TO print the solution
{
    cout <<"Vertex Distance from Source" << endl;
    for (int i = 2; i < m; i++){
        cout << "Distance of " << i << " from vertex " << src << ": " << dist[i] << endl;
    }
}

void dijkstra(int m,int src, int graph[][N],int w_vert[]) // Algorithm to find the shortest distance from the source vertex
{
    int dist[m];                                          // array to store the minimum weight from source vertex
    //int p_dist[m];                                        // array to store product of weight of vertex
    bool sptSet[m];                                       // array to store whether a vertex is visited or not
    for (int i = 1; i < m; i++)                           // initializing all vertex dis as infinity and not visited
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = w_vert[src];                                       // distance of source vertex from itself is always zero
    //p_dist[src] = w_vert[src];                           // product of source vertex from itself is weight of itself

    for (int count = 0; count < m - 1; count++) {
        int u = minDistance(dist, sptSet,m);             // choosing minimum distance vertex

        sptSet[u] = true;
        for (int v = 0; v < m; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] + w_vert[v] < dist[v]){// updating the dist array and p_dist only if new distance is less than previous distance and vertex is not visited before
                dist[v] = dist[u] + graph[u][v] + w_vert[v];
                //p_dist[v] = p_dist[u] + w_vert[v];
            }
    }
    Solution(dist,m,src);     // To print solution
}

int main(){
    int n;
    cout << "Write the number of vertices in the undirected graph: ";
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1,false);
    cout << "Write -1 to indicate the end of neighbors" << endl;
    int y;
    for(int i = 1; i < n+1; i++){
        cout << "Write neighbors of vertex " << i << ": ";
        while(1){
            cin >> y;
            if(y == -1)
                break;
            adj[i].push_back(y);
        }
    }
    int weight[N][N];                          // To store the weight of edges
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            weight[i][j] = 0;
        }
    }
    for(int i = 1; i < n+1; i++){
        for(auto j: adj[i]){
            if(j > i){
                cout << "Weight of the edge {" << i << "," << j << "}: ";
                cin >> weight[i][j];
                weight[j][i] = weight[i][j];
            }
        }
    }
    int w_vert[n+1];                      // To store the weight of vertex
    w_vert[0] = 0;
    for(int i = 1; i < n+1; i++){
        cout << "Weight of the vertex " << i << ": ";
        cin >> w_vert[i];
    }
    int src = 0;
    cout << "Write source vertex: ";
    cin >> src;
    dijkstra(n+1,src,weight,w_vert);
//    for(int i = 1; i < n+1; i++){
//        for(int j = 1; j < n+1; j++){
//            cout << weight[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for(int i = 1; i < n+1; i++)
//        cout << w_vert[i] << " ";
//    cout << "Adjacency List:" << endl;
//    for(int i = 1; i < n+1; i++) // To print adjacency list
//    {
//        cout << i << " -> ";
//        vector<int>::iterator it;  // defining an iterator which is a pointer to traverse vector
//        for(it = adj[i].begin(); it != adj[i].end(); it++)
//            {cout << *it << " ";
//
//            }
//        cout << endl;
//    }
//    DFS_Recursive(0,adj,vis);

    return 0;
}
