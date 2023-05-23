// To count the number of 1s present in a binary number
#include <iostream>
using namespace std;
int countone( int n)
{
    int count = 0;
    while (n)
    {
        n = n & n-1;      // When we take (n & n-1) then there is one less 1 in this new number than n
        count ++;
    }
    return count;
    
}
int main()
{
    cout << countone(19);
    return 0;
}