#include <iostream>
using namespace std;
void hanoi(int n,char org,char dest,char help)
{
    if (n==0)
        return;
    hanoi(n-1,org,help,dest);
    cout << " Moving from " << org << "to"<< dest<< endl;
    hanoi(n-1,help,dest,org);
}
int main()
{
    hanoi(3,'A','c','B');
    return 0;
}
