// Name: Dhanraj Kumar  Roll no: 20CE10021
#include<bits/stdc++.h>
using namespace std;

void read_graph(int n, int e,vector<vector<int>> &adj,vector<int> &indegree){     // TO read graph
    int y;
    for(int i = 0; i < n; i++){
        cout << i << ":";
        while(1){
            cin >> y;
            adj[i].push_back(y);
            indegree[i]++;
            if(cin.get() == '\n')
                break;
        }
    }
}

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

void Two_set(int src,vector<vector<int>> &adj, vector<bool> &vis,vector<int> &s, bool &Odd_cycle,int P_set) // This function divide whole graph vertices into two set
{
    if( s[src] != -2 and s[src] != P_set)  // If it can't be divided into two sets then there exist a odd length cycle and if there is odd length cycle then no conflict shedule exists
    {
        Odd_cycle = false;
        return;
    }
    s[src] = P_set;
    if(vis[src])
        return;
    vis[src] = true;
    for(auto i: adj[src])
    {
        Two_set(i,adj,vis,s,Odd_cycle,P_set xor 0);
    }
}

void trivial(vector<vector<int>> &adj, vector<bool> &vis,vector<int> &indegree,int n){      // TO find trivial vertex
    cout << "The trivial vertices of the graph are:" << endl;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 1)                                  // if there is vertex of indegree 1 then that must be trivial vertex
            cout << i << " ";
    }
    cout << endl;
}

int main(){
    int n, e;
    cout << "n = ";
    cin >> n;
    cout << "e = ";
    cin >> e;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
    vector<bool> vis(n+1,false);
    vector<int> s(n+1,-2);
    cout << "Reading graph..." << endl;
    read_graph(n,e,adj,indegree);
//    cout << "Adjacency List:" << endl;
//    for(int i = 0; i < n; i++) // To print adjacency list
//    {
//        cout << i << " -> ";
//        vector<int>::iterator it;  // defining an iterator which is a pointer to traverse vector
//        for(it = adj[i].begin(); it != adj[i].end(); it++)
//            {cout << *it << " ";
//
//            }
//        cout << endl;
//    }
    //DFS_Recursive(0,adj,vis);
    bool Odd_cycle = true;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            Two_set(i,adj,vis,s,Odd_cycle,1);
    }
    if(Odd_cycle)
        cout << "There exists conflict-free schedule." << endl;
    else
        cout << "There exists no conflict-free schedule." << endl;
    trivial(adj,vis,indegree,n);
    return 0;
}
