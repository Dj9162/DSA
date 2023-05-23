// C++ program to calculate all possible paths to reach the end point on a maze board
#include <iostream>
int maze(int n,int i, int j)
{
    if (i == n-1 || j == n-1)
        return 1;
    
    if(i>n ||j>n)
        return 0;

    return maze(n,i+1,j) + maze(n,i,j+1);
    
}
int main()
{
    std::cout << maze(3,0,0) << std::endl;
    return 0;
}