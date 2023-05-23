#include<bits/stdc++.h>
using namespace std;

string solve(vector<int> &A){
    if(A.size() == 1)
        return "Yes";
    else if(A.size() == 2){
        if(A[0] < A[1])
            return "Yes";
        else
            return "No";
    }

    bool flag = true;
    for(int i = 0; i < A.size() - 1; i++){
        if(A[i] != A[i+1]){
            flag = false;
            break;
        }
    }
    if(flag){
        return "No";
    }
    return "Yes";
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cout << solve(A) << endl;

	return 0;
}
