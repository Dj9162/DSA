// Name: Dhanraj Kumar  Roll no: 20CE10021  Test: 2
#include<iostream>
#include<vector>
using namespace std;
#define N 100

void read_graph(int n,vector<vector<int>> &adj,vector<int> &indegree){     // TO read graph
    cout << "Write -1 to indicate the end of neighbors" << endl;
    int y;
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        while(1){
            cin >> y;
            if(y == -1)
                break;
            adj[i].push_back(y);
            indegree[i]++;
        }
    }
}

// int lng_dp(int i,int j,int n,int matrix[][N],vector<vector<int>>& dp){
//    if(i>=n or j>=n or i<0 or j<0)                                       // base case if i and j exit from matrix then return
//        return 0;
//    if(dp[i][j]!=-1)
//        return dp[i][j];
//    int v = 1;
//    if(i+1<n and j<n and i+1>=0 and j>=0 and matrix[i+1][j]>matrix[i][j]){      // Finding path from right index
//        v = max(v,lng_dp(i+1,j,n,matrix,dp)+1);
//    }
//    if(i-1<n and j<n and i-1>=0 and j>=0 and matrix[i-1][j]>matrix[i][j]){       // Finding path from left index
//        v = max(v,lng_dp(i-1,j,n,matrix,dp)+1);
//    }
//    if(i<n and j-1<n and i>=0 and j-1>=0 and matrix[i][j-1]>matrix[i][j]){       // Finding path from down index
//        v = max(v,lng_dp(i,j-1,n,matrix,dp)+1);
//    }
//    if(i<n and j+1<n and i>=0 and j+1>=0 and matrix[i][j+1]>matrix[i][j]){        // Finding path from upper index
//        v = max(v,lng_dp(i,j+1,n,matrix,dp)+1);
//    }
//    return dp[i][j] = v;
//}

int longest_path(int G[][N],int s, int m){
    int lng_dis[m];                            // To store the longest distance of vertex from source vertex
    bool vis[m];
    for(int i = 0; i < m; i++)
        lng_dis[i] = -1;
    for(int i = 0; i < m; i++)
        vis[i] = false;
    lng_dis[s] = 0;

    for(int i = 0; i < m-1; i++){

        int max_dis = -1,r_idx = 0;

        for(int j = 0; j < m; j++){
            if(vis[j] == false && lng_dis[j] >= max_dis){
                max_dis = lng_dis[j];
                r_idx = j;
            }
        }

        vis[r_idx] = true;

        for(int j = 0; j < m; j++){
            if(vis[j] == false && G[r_idx][j] != 0 && lng_dis[r_idx] != -1){
                if(lng_dis[r_idx] + G[r_idx][j] > lng_dis[j]){
                    lng_dis[j] = lng_dis[r_idx] + G[r_idx][j];
                }
            }
        }

    }
    int maxi = lng_dis[0];
    for(int i = 1; i < m; i++){
        if(lng_dis[i] > maxi)
            maxi = lng_dis[i];
    }
    return maxi;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    vector<vector<int>> adj(n);
    vector<bool> vis(n);
    vector<int> indegree(n,0);
    for(int i = 0; i < n; i++)
        vis[i] = false;

    cout << "Reading graph..." << endl;
    read_graph(n,adj,indegree);
    int G[N][N];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            G[i][j] = 0;
    }

    for(int i = 0; i < n; i++){
        for(auto j: adj[i])
            G[i][j] = 1;
    }

    int maxi = -1;
    for(int i = 0; i < n; i++){
        int a = longest_path(G,i,n);
            if(a > maxi)
                maxi = a;
    }
    cout << "Length of the longest path: " << maxi << endl;
//    vector<vector<int>> dp(n);
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++)
//            dp[i][j] = -1;
//    }
//    int ans = 0;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                if(dp[i][j]==-1)
//                    ans = max(ans,lng_dp(i,j,n,G,dp));
//            }
//        }
//    cout << "DP: " << endl;
//    cout << "Length of the longest path: " << ans << endl;


    return 0;
}
