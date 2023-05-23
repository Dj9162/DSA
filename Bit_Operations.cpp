/* Important Bitwise operations to remember*/
#include <iostream>
using namespace std;

int getbit(int n, int pos)                           // To find whether that place is 0 or 1 in binary number
{
    return ((n & (1 << pos)) != 0);
    /* Let n = 5 = 0101 and pos = 2
       then (1 << 2) = 1 * 2^2 = 4 = 0100
       Now, 5 &( 1 << 2) = 0100 = 4 != 0
       Now, Let pos =1
       then (1 << 1) = 1 * 2^1 =2 =0010
       Now, 5 & ( 1 << 1) = 0000 = 0
       It shows that when there is zero on that place then it expression gives 0 otherwise not zero
    */
}

int setBit( int n, int pos)             // To set 1 on the given position
{
    return (n | (1 << pos));
    /* Let n =5 = 0101 and pos = 1
       then (1 << 1) = 2 =0010
       Now, 5 | (1 << 1) = 0111
    */
}
 
int clearBit(int n, int pos)            // To set 0 on the given position
{
    int temp = ~(1 << pos);
    return (n & temp);
    /* Let n = 5 = 0101 and pos =2
       then (1 << 2) = 0100 and ~( 1 << 2) = 1011
       so, 0101 & 1011 = 0001
    */
}

int updateBit(int n, int pos, int value)           // To update 0 or 1 at the given position
{
    int temp = ~(1<< pos);
    n = n & temp;
    return (n | ( value << pos));
    /* It is mixer of clearbit and setbit
       Let n = 5= 0101 and pos = 2 and value =0
       temp = ~(1 << 2) = ~( 0100) = 1011
       n = 0101 & 1011 = 0001
       So, (n | (0 << 2)) = ( 0001 | 0000) = 0001
    */
}
int main()
{
    // cout << getbit(5,2);
    // cout << setBit(5,1);
    // cout << clearBit( 5,2);
    cout << updateBit(5,1,1);
    return 0;
}