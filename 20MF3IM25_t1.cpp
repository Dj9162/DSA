#include<iostream>

using namespace std;
const int N = 100;
int comp1 = 0;

void swap(int *a, int *b){  // To swap two elements using function
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_arr(int arr[N][N] , int i, int j, int m, int n) { // To swap two rows of an array using function

    for(int k = 0; k < m; k++){
        swap(&arr[i][k], &arr[j][k]);
    }

}

int compare(int arr[N][N] , int d, int idx1, int idx2){     // To compare two arrays and to check lexicography

    for(int i = 0; i < d; i++){
        comp1++;
        if(arr[idx1][i] < arr[idx2][i]){
            return -1;
        }
        else if(arr[idx1][i] > arr[idx2][i]){
            return 1;
        }
    }
    
    return 0;
}

int partition(int arr[N][N] , int low, int high, int m, int n)
{
    int pivot = high;
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
       
        if (compare(arr, m, pivot, j) == 1) {
            i++;
            swap_arr(arr, i, j, m, n);
        }
    }
    swap_arr(arr, i+1, high, m, n);
   
    return (i + 1);
    
}

void sort(int arr[N][N] , int low, int high, int n, int m)      // Using quicksort sorting
{
    if (low < high) {
        comp1++;
        int pi = partition(arr, low, high, m, n);
 
        sort(arr, low, pi - 1, n, m);
        sort(arr, pi + 1, high, n, m);
    }
}

int main(){
    int arr[N][N];
    int d = 3, n = 0;
    cin >> d >> n;

    arr[n][d];

    cout << "Enter " << n << "  points, one in each line " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> arr[i][j];
        }
    }
  
    sort(arr, 0, n-1,n, d);

    cout << "---QUIKSORT---" << endl;
    cout << "Sorted Array: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Number of single integer comparisons: " << comp1 << endl;

    return 0;
}