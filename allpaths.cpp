// C++ program to count the all posible paths to reach from starting point to end point using a Dice
#include <iostream>
using namespace std;
int path(int s,int e)
{
    if ( s==e)
    {
        return 1;
    }
    if(s>e)
    return 0;
    
    int count = 0;
    for (size_t i = 1; i <= 6; i++)
    {
        count +=path(s+i,e);
    }
    return count;
}
int main()
{
    cout << path(0,0);
    return 0;
}