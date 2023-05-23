// C++ program to show Adjacency matrix and Adjacency List of graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> adj[N];    // Array of vectors defined to store adjacency list of graph
int main()
{
    int n,m;      // Taking n as total vertices of graph and m as total edges of graph
    cin >> n >> m;

    // vector<vector<int>> adjm(n+1,vector<int>(n+1,0)); // Making 2D vector to store Adjacency matrix of graph
    // for(int i = 0; i < m ; i++)  // Loop to input connection between two vertices
    // {
    //     int x,y;
    //     cin >> x >> y;

    //     adjm[x][y] = 1;   // Assuming that A is connected to B, then
    //     adjm[y][x] = 1;   // B will also be connected to A
    // }
    // cout << "Adjacency Matrix:-" << endl;

    // for(int i = 1; i < n+1; i++)  // To print Adjacency Matrix
    // {
    //     for(int j = 1; j < n+1; j++)
    //         cout << adjm[i][j] << " ";
    //     cout << endl;
    // }

    // if(adjm[3][7] == 1)   // To search if there is connection between 3 and 7 or not
    //     cout << "Edge Found!" << endl;
    // else
    //     cout <<" No Edge Found!" << endl;

    cout << endl << endl;

    for(int i = 0; i < m ; i++)  // To set connections for Adjacency list
    {
        int x, y; 
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> temp(n+1);
    cout << "Adjacency List:" << endl;
    for(int i = 1; i < n+1; i++) // To print adjacency list
    {
        cout << i << " -> ";
        vector<int>::iterator it;  // defining an iterator which is a pointer to traverse vector
        for(it = adj[i].begin(); it != adj[i].end(); it++)
            {cout << *it << " ";
             if (i > *it)
                temp[i]++;
            }
        cout << endl;
    }
    for(int i = 1; i <= n; i++)
        cout << temp[i] << " ";
    return 0;
}