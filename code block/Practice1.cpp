#include<bits/stdc++.h>
using namespace std;

int l_search(vector<int> &v, int a){
    int l = 0, r = v.size()-1;
    int ans =0;

    while(l <= r){
        int m = l + (r - l)/2;

        if(v[m] >= a){
            ans = m;
            r = m -1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int r_search(vector<int> &v, int a){
    int l = 0, r = v.size()-1;
    int ans =r;

    while(l <= r){
        int m = l + (r - l)/2;

        if(v[m] <= a){
            ans = m;
            l = m +1;
        }
        else
            r = m - 1;
    }
    return ans;
}

vector<int> solve(vector<vector<int>> &v, vector<vector<int>> query){
    vector<int> row_sum, col_sum;

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            row_sum[i] += v[i][j];
            col_sum[j] += v[i][j];
        }
    }
    vector<int> total_sum;
    for(int i = 0; i < row_sum.size(); i++)
        total_sum.push_back(row_sum[i]);
    for(int j = 0; j < col_sum.size(); j++)
        total_sum.push_back(col_sum[j]);

    sort(total_sum.begin(), total_sum.end());
    vector<int> ans;

    int l = l_search(total_sum, a);
    int r = r_search(total_sum, b);
    ans.push_back(r - l + 1);

}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> v[i][j];
    }

    int q,s;
    cin >> q;
    cin >> s;
    while(q--){
        int a, b;
        cin >> a >> b;
        count(v, n, m, a, b);
    }


    return 0;
}
