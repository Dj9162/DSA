#include<iostream>
#include<math.h>
using namespace std;

void swap(int *x, int *y, int *a, int *b, int *c, int *d)
{
    int temp = *x;
    *x = *b;
    *b = temp;

    temp = *y;
    *y = *c;
    *c = temp;

    temp = *a;
    *a = *d;
    *d = temp;
}

class minheap{
    public:
    int capacity;
    int **arr;
    int idx;
    
    minheap(int cap){
        capacity = cap;
        idx = 0;
        arr = new int*[capacity];
        for(int i = 0; i < capacity; i++){
            arr[i] = new int[3];
        }
    }
   
    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (2*i + 1);}
    int right(int i){ return (2*i + 2);}

    void insert(int a, int b, int c)                   // function to insert key in the heap array
    {
        if(idx == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        idx++;
        int i = idx - 1;
        arr[i][0] = a, arr[i][1] = b, arr[i][2] = c;                       // insert key at the end of array
        while(i != 0 && arr[parent(i)][2] > arr[i][2])      // loop to convert array into min heap means if parent is greater than child then swap them
        {
            swap(&arr[i][0],&arr[i][1],&arr[i][2],&arr[parent(i)][0],&arr[parent(i)][1],&arr[parent(i)][2]);
            i = parent(i);
        }
    }

    void MinHeapify(int i)
    {
        int l = left(i);  // to store left child index
        int r = right(i); // to store right child index
        int smallest = i; // to store smallest child index
        if(l< idx && arr[l][2] < arr[i][2]) // if left child is lesser than parent
            smallest = l; // then change smallest variable to left child index
        if(r < idx && arr[r][2] < arr[smallest][2])
            smallest = r;
        if(smallest != i)
        {
            swap(&arr[i][0], &arr[i][1], &arr[i][2], &arr[smallest][0], &arr[smallest][1], &arr[smallest][2]); // swap parent element and lesser value child
            MinHeapify(smallest); // convert them into min heap
        }
    }

    int* extractMin() // top element of min heap is always lesser
    {
        int *error = new int[3];
        error[0] = -1,error[1] = -1,error[2] = -1; 
        if(idx < 0)
            return error;
        if(idx == 1)
        {
            idx--;
            return arr[0];
        }
        int *Mini = new int[3];
        Mini[0] = arr[0][0], Mini[1] = arr[0][1], Mini[2] = arr[0][2];
        arr[0][0] = arr[idx-1][0], arr[0][1] = arr[idx-1][1], arr[0][2] = arr[idx-1][2];
        idx--;
        MinHeapify(0); // convert the left elements into min heap
        return Mini;
    }

};

int main(){
    int n = 0;
    cout << "n = ";
    cin >> n;

    minheap h(n+1);
    for(int i = 0; i < n+1; i++){
        h.insert(i, 0, i*i*i);
    }
    
    cout << "2-way Ramanujan Numbers... " << endl;
    int ans[101] = {0}, index = 0;
    while(h.idx > 0){
        int *out = h.extractMin();

        if(out[1] < n)
            h.insert(out[0], (out[1]+ 1), ((out[0] * out[0] * out[0]) + ((out[1] + 1) * (out[1] + 1) * (out[1] + 1))));
        
        for(int i = 0; i < h.idx; i++){
        
            for(int j = 0; j < h.idx; j++){
                
                if( (i != j) && (h.arr[i][2] == h.arr[j][2]) && ((h.arr[i][0] != h.arr[j][0]) && (h.arr[i][1] != h.arr[j][1]) && (h.arr[i][0] != h.arr[j][1]) && (h.arr[i][1] != h.arr[j][0])) ){
                    int flag = 0;
                    for(int k = 0; k < 101; k++){
                        if(h.arr[i][2] == ans[k]){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        ans[index++] = h.arr[i][2];
                        cout << h.arr[i][2] << " ( " << h.arr[i][0] << ", " << h.arr[i][1] << ") " <<  " ( " << h.arr[j][0] << ", " << h.arr[j][1] << ") " << endl;
                    }
                    
                    
                }
            }
        }
        
    }

    minheap h1(2*n+1);
    for(int i = -n; i < n+1; i++){
        h1.insert(i, 0, i*i*i);
    }
    cout << endl << endl;
    
    cout << "Weak 2-way Ramanujan Numbers... " << endl;
    int ans1[10001] = {0}, index1 = 0;
    while(h1.idx > 0){
        int *out = h1.extractMin();

        if(out[1] < n)
            h1.insert(out[0], (out[1]+ 1), ((out[0] * out[0] * out[0]) + ((out[1] + 1) * (out[1] + 1) * (out[1] + 1))));
        
        for(int i = 0; i < h1.idx; i++){
        
            for(int j = 0; j < h1.idx; j++){
                
                if( (i != j) && (h1.arr[i][2] > 0) && (h1.arr[i][2] == h1.arr[j][2]) && ((h1.arr[i][0] != h1.arr[j][0]) && (h1.arr[i][1] != h1.arr[j][1]) && (h1.arr[i][0] != h1.arr[j][1]) && (h1.arr[i][1] != h1.arr[j][0])) ){
                    int flag = 0;
                    for(int k = 0; k < index1; k++){
                        if(h1.arr[i][2] == ans1[k]){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        ans1[index1++] = h1.arr[i][2];
                        cout << h1.arr[i][2] << " ( " << h1.arr[i][0] << ", " << h1.arr[i][1] << ") " <<  " ( " << h1.arr[j][0] << ", " << h1.arr[j][1] << ") " << endl;
                    }
                    
                    
                }
            }
        }
        
    }
    

    return 0;
}