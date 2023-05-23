// Name: Dhanraj Kumar  Roll no: 20CE10021  Assignment no: 2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int Recursion(int arr[], int price[], int apple, int size) // Recursive approach to find maximum profit
{
    const int n = size;
	// Base Case
	if (apple == 0 || size == 0) // if apples are empty then return
		return 0;
    if(size == 0) // if first loop is complete then start again from end
        size = n;

	if (price[size - 1] > apple)// If left apple is less than family size then go to next family
		return Recursion(arr, price, apple, size - 1);
	else     // Returning maximum profit either this family buys or not
		return max(price[size - 1]*arr[size-1]+ Recursion(arr,price, apple-arr[n-1], size),Recursion(arr, price, apple, size - 1));
}

int DP(int apple, int size,int price[], int arr[])   // Dynamic approach to find maximum profit
{
    int ans[apple+1];                                // To store all profits
    for(int i = 0; i < apple+1; i++)                 // Initialize ans with 0
        ans[i] = 0;

    for (int i = 0; i < apple+1; i++)
      for (int j = 0; j < size; j++)
         if (arr[j] <= i)
            ans[i] = max(ans[i], ans[i-arr[j]] + arr[j]*price[j]);       // change value of ans with maximum profit

    return ans[apple];
}


int main(){
    int n = 0, m = 0;
    cout << "Write the number of apples that Ramu has: ";
    cin >> n;
    cout << "Write the number of buyers: ";
    cin >> m;
    int* fam = new int[m];   // Dynamic array to store family size
    cout << "Write family sizes: " << endl;
    for(int i = 0; i < m; i++)
        cin >> fam[i];
    int* price = new int[m]; // Dynamic array to store price of each family
    cout << "Write prices:" << endl;
    for(int i = 0; i < m; i++)
        cin >> price[i];
    int* ans = new int[m]; // To store final answer
    for(int i = 0; i < m; i++)
        ans[i] = 0;
    cout << "Output of recursive implementation" << endl;
    cout << Recursion(fam,price,n,m)<< endl;
    cout << DP(n,m,price,fam);

}

