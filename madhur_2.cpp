#include <iostream>
#include <time.h>
using namespace std;

int Multiplication_cost(int p[], int l, int r)
{
    if (l == r)
        return 0;
    int min_cost = 100001;
 
    for (int i = l; i < r; i++)
        min_cost = min(Multiplication_cost(p, l, i) + Multiplication_cost(p, i + 1, r) + p[l - 1] * p[i] * p[r], min_cost);
 
    return min_cost;
}

int poly_order(int p[], int n)
{
 
    int cost[n][n] = {0};
 
    for (int i=1; i<n-1; i++){
        for (int j=1; j<n-i; j++){
            cost[j][j+i] = min(cost[j+1][j+i] + p[j-1]*p[j]*p[j+i], cost[j][j+i-1] + p[j-1]*p[j+i-1]*p[j+i]);
        }    
    }
      
    return cost[1][n-1];
}

int main(){

    int n = 5, l = 1, r = 5;
    int a[5] = { 1, 2, 3, 4, 3 };
    int p[5]= {10, 20, 30, 40, 30};


    clock_t start1 = clock();
    int result1 = Multiplication_cost(p,l,r-1);
    clock_t end1 = clock();


    cout << "Result1: " << result1 << endl;
    cout << "Time Spent: " << (end1-start1)/ CLOCKS_PER_SEC << endl;

    clock_t start2 = clock();
    int result2 = poly_order(p,n);
    clock_t end2 = clock();
    cout << "Result2: " << result2 << endl;
    cout << "Time Spent: " << (end2-start2)/ CLOCKS_PER_SEC << endl;


    return 0;
}