#include <bits/stdc++.h>
using namespace std;

int coprime(unordered_map<int,vector<int>> &children,vector<int> &child,vector<int>&val,int parent){
    int count=0;
    queue<int> q;
    for(int i=0;i<child.size();i++){
        q.push(child[i]);
    }
    while(!q.empty()){
        int childval=val[q.front()-1];
        q.pop();
        if(__gcd(parent,childval)==1){
            count++;
        }
        auto it=children.find(q.front());
        if(it!=children.end()){
            for(int i=0;i<it->second.size();i++){
                q.push(it->second[i]);
            }
        }
    }
    return count;
}

int solve(int n,vector<int> &par,vector<int> &val){
    unordered_map<int,vector<int>> children;
    for(int i=0;i<par.size();i++){
        children[par[i]].push_back(i+2);
    }
    int count=0;
    for(auto it=children.begin();it!=children.end();it++){
        if(it->second.size()!=0){
            count+=coprime(children,it->second,val,val[(it->first)-1]);
        }
    }
    return count;

}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

    int n=5;
    vector<int> par={1,1,3,3};
    vector<int> val={1,2,3,4,5};
    cout<<solve(n,par,val);
    return 0;
}
