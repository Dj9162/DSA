#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 0;
    cin >> t;
    while(t--){
        long long n, m, p1,p2, x, y;
        cin >> p1 >> p2;
        cin >> n >> m;

        if(n > m){
            if(p1 * m < p2 * (m + 1)){
                y = n / (m + 1);
                x = n - y * (m + 1);
                cout << y * p1 * m + x * min(p1,p2) << endl;
            }
            else
            cout << n * min(p1, p2) << endl;
        }
        else
            cout << n * min(p1, p2) << endl;

    }

    return 0;
}