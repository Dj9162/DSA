// Name: Dhanraj Kumar   Roll no: 20CE10021
// C++ program to calculate total number of pairs in which first occurring element is greater than two times the second occurring in given ranking array
#include<iostream>
using namespace std;

int dist1(int r[], int n){               // Function to calculate required number of pairs of ranking
    int cnt = 0;                          // To store total number of pairs
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(r[i] > 2*r[j])              // Checking whether the pair satisfies the required condition or not
                cnt++;                     // If satisfy then add 1 to cnt variable else do not add 1
        }
    }
    return cnt;                            // Returning total number of pairs which satisfied our condition
}  // Time complexity = O(n^2)
// Space complexity = O(1)


int dist2(int a,int s, int e,int r[]){     // Function to calculate required number of pairs of ranking
    if(s == e){                             // if there is only one element left in the array then compare it with passed element whether it satisfies required condition or not
        if(a > 2*r[s])
            return 1;                       // If it satisfies then return 1
        else
            return 0;                        // If it does not satisfy then return 0
    }
    int m = s + (e - s)/2;                          // calculating mid element of array to divide it into two parts
    return dist2(a,s,m,r) + dist2(a,m+1,e,r);        // return total number of required pairs from first half and second half of divided array
} // Time complexity = O(log n) as binary search algorithm
// Space complexity = O(1)

int main()
{
    int n;                                                   // To store number of elements in Ranking array
    cout << "n = ";
    cin >> n;
    int *r = new int[n];                                     // Dynamically allocated array r to store rankings
    cout << "Ranking: ";
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    cout << "Distance by method 1: " << dist1(r,n) << endl;      // Calling method 1 function
    int cnt = 0, i = 0;                                          // Here cnt variable to store total number of required pairs and i to store index of elements in array
    while(i < n-1){                                             // loop to count total number of pairs in which first element is r[i] and second element is element which comes after r[i] and satisfy required conditions
        cnt += dist2(r[i],i+1,n-1,r);                            // adding total number of pairs which satisfied by placing r[i] as first element in cnt
        i++;
    }// Overall Time complexity = O(n*log n) // where n from loop and log n from dist2 function
    cout << "Distance by method 2: " << cnt << endl;
}
