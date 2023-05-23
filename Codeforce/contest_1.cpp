#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n,m,i1,j1,i2,j2;
	    string s;
	    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
	    cin >> s;
	    // cout << n << " " << m << endl;
	    int i = i1, j = j1;
	    int bounce = 0;
	    int d1 = 0, d2 = 0;
	    if(s[0] == 'D')
	        d1 = 1;
	    if(s[0] == 'U')
	        d1 = -1;
	    if(s[1] == 'L')
	        d2 = -1;
	    if(s[1] == 'R')
	        d2 = 1;

        // i = i + d1;
	    // j = j + d2;
        int flag = 0;
	    while(1){
            cout << i << "->" << j << endl;
	        if((i == n) || (i == 1)){
	            d1 = -d1;
                bounce++;
                
	        }
	        if((j == m) || (j == 1)){
	            d2 = -d2;
                bounce++;
            }
            
	        i = i + d1;
	        j = j + d2;
            if(i < 1 || i > n || j < 1 || j > m)
                break;
            if(i == i2 && j == j2)
                break;
	    }
	    if((i == n-1 && j == m-1) && (i2 == n-1 && j2 == m-1))
	        bounce++;
	    if(i == n-1 && j == m-1)
	        cout << -1 << endl;
	    else
	        cout << bounce << endl;
	}
	
	return 0;
}
