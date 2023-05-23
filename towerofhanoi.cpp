// Program to solve Tower of Hanoi
#include <iostream>
using namespace std;
void hanoi(int n,char org,char dest,char help)
{
    if (n==0)
        return;
    hanoi(n-1,org,help,dest);                                     // Asking upper n-1 block to set their destination to B and helper to C
    cout << "Move from " << org << " to "<< dest<< endl;
    hanoi(n-1,help,dest,org);                                     // After moving n-1 block to thier destination, asking to set upper n-1 block to
}                                                                // set their destination to C, helper to A and source to B
int main()
{
    hanoi(6,'A','C','B');
    return 0;
}