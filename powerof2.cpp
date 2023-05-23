// To check number is power of 2 or not
#include <iostream>
using namespace std;

int Ispower( int n)                 // To check number is power of 2 or not
{
    return !(n && (n & n-1));
    /* There is a trick that all the number which is power of 2 when converted into binary number 
       there is only one setbit means 1 except that there is all 0 and that 1 is in leftmost position.
       And when we take a number which is only 1 lesser than a number in binary number then 
       from the rigthmost 1 all the digits are interchanged means 1 becomes 0 and 0 becomes 1.
       so, from above conditions when we take & of n and n-1 then we get always 0 only for number which is power of 2
       Let n = 8 = 1000 
       so, n-1 = 7 = 0111
       so, n & n-1 = 0000
    */
}
int main()
{
    cout << Ispower(16);
    return 0;
}