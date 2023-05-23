// C++ program to make 2d dynamic array in which each index of array contain a variable size array
#include <iostream>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    int** arr = new int* [n];                 // Dynamic 2d array
    for( int i=0 ; i < n ; i++)
    {
        int a;
        cin >> a;
        int* b = new int [a];              // Dynamic 1d array for each index of 2d array
        for( int j =0; j < a; j++)
        {
            int e;
            cin >> e;
            b[j] = e;
        }
        *(arr + i) = b;                   // To store array in each index of array
    }
    for(int i =0 ; i < q; i++)
    {
        int r,s;
        cin >> r >> s; 
        cout << arr[r][s] << endl;
    }
      
    return 0;
}
