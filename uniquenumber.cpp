// C program to find unique element in an array
#include <iostream>
using namespace std;
int getbit( int n, int pos)
{
    return((n & (1 << pos)) != 0);
}
int setbit( int n, int pos)
{
    return (n | ( 1 << pos));
}
int unique1( int arr[], int n)   // Function to find unique element in an array which has only one unique element and all are repeated twice
{
    /* If we take xor of two same number then it always gives 0
       and when we take xor of 0 and a number then it always gives same number
       So, If we take xor of all numbers in array then it will automatically give unique number
    */
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp ^ arr[i];
    }
    return temp;
    
}
void unique2( int arr[], int n)      // Function to find two unique element except that all are repeated twice
{
    int xorall = 0;
    for (int i = 0; i < n; i++)         // xor of all elements of array, it gives xor of two unique elements
        xorall = xorall ^ arr[i];
    int setbit =0, pos=0,temp= xorall;  // Here temp store value of xor of all elements
    while (setbit !=1)                  // This loop is to find position of rightmost 1 in binary number
    {
        setbit = xorall & 1;
        pos ++;
        xorall = xorall >> 1;
    }
    int newxor =0;
    for (int i = 0; i < n; i++)       // This loop is to find one unique element
    {
        if (getbit(arr[i],pos-1))       // This is to find if there is any number in the array which has 1 at same position as calculated
        {
            newxor = newxor ^ arr[i];    // It gives one unique element
        }
        
    }
    cout << newxor << " ";
    cout << (newxor ^ temp) << endl;       // It gives next unique element
      
}
int unique3(int arr[], int n)              // Function to find unique element if there are all repeated thrice except that
{
    int result =0;
    for (int i = 0; i < 64; i++)           // To trace all 64 bit of a binary number
    {
        int sum = 0;
        for (int j = 0; j < n; j++)        // To trace all elements of array
        {
            if (getbit( arr[j], i))         // To check if ith position of element j of array is 1 or not
            {
                sum++;
            }   
        }
        if (sum % 3 != 0)
        {
            result = setbit( result, i);            // TO change the ith position of result binary number into 1
        }
        
    }
    return result;
}
int main()
{
    int arr[] = {1,5,7,35,6,7,1,5,6,7,1,5,6};
    cout << unique3( arr, 13);
    return 0;
}