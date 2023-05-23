#include <iostream>
#include <vector>

using namespace std;
//vector<int> dp(6, -1);

int fib(int n){
    cout << "Called" << endl;

    if(n == 0 || n == 1)
        return n;
    // if(dp[n] != -1)
    //     return dp[n];
    return fib(n-1) + fib(n-2);
}

int main()
{
    cout << fib(5) << endl;

    return 0;
}
