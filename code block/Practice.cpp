#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;  cin>>t;
    while(t--){
        int n,m;
        cin >>n >> m;

        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0, mini, maxi;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                mini = a[i];
                break;
            }
            else if(a[i] < b[i]){
                i++;
            }
            else
                j++;
        }

        int l = a.size()-1, r = b.size()-1;
        while(l >= 0 && r >= 0){
            if(a[l] == b[r]){
                maxi = a[l];
                break;
            }
            else if(a[l] < b[r])
                r--;
            else
                l--;
        }
        if(mini == maxi || i == a.size() || j == b.size() || l < 0 || r < 0){
            cout << 0 << endl;
            break;
        }
        int area = maxi - mini;
        cout << area << endl;

    }


    return 0;
}
