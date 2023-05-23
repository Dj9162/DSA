// C++ program to DFS search in graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int vis[N];
bool visited[N];
vector<int> adj[N];

void DFS_Recursive(int node)
{
    // preorder
    vis[node] = 1;
    cout << node << " ";

    // Inorder
    vector<int> :: iterator it;
    for(it = adj[node].begin() ; it != adj[node].end() ; it++)
    {
        if(!vis[*it])
        {
            DFS_Recursive(*it);
        }
    }
    // postorder
    //cout << node << " ";
}

void DFS_iterative(int start)
{
    stack <int> st;
    st.push(start);
    visited[start] = true;
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        cout << temp << " ";
        vector<int> :: iterator it;
        for(it = adj[temp].begin() ; it != adj[temp].end() ; it++)
        {
            if(!visited[*it])
            {
                st.push(*it);
                visited[*it] = true;
            }
        }
    }
}

int main()
{

    int n,m;
    cin >>n >> m;

    for(int i = 0; i < n; i++)
        vis[i] = 0;
    
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    int x,y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS_Recursive(1);
    cout << endl;
    DFS_iterative(1);
    
    return 0;
}