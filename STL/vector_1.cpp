#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        // v.size() -> O(1)
        cout << v[i] << " ";
    }
    cout << endl;
    
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> v;
    v.push_back(7);
    v.push_back(6);

    vector<int> v2 = v; //O(n)
    v2.push_back(5);
    printVec(v);
    printVec(v2);
    return 0;
}
