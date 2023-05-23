#include<iostream>
using namespace std;
void swap(int *x, int *y)             // To swap two elements
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
class MinHeap{                              // To Implement MinHeap;
    int harr[100];
    int heap_size;
    public:
        void MinHeapify(int j);
        int parent(int i){ return (i-1)/2;}
        int left(int i){ return (2*i + 1);}
        int right(int i){ return (2*i + 2);}
        int getMin(){ return harr[0];}
        int getmedian();
        void insertKey(int k);
        MinHeap(){heap_size = 0;}
};

class MaxHeap{                                 // To Implement MaxHeap;
    int harr[100];
    int heap_size;
    public:
        MaxHeap(){heap_size= 0;}
        void MaxHeapify(int j);
        int parent(int i){ return (i-1)/2;}
        int left(int i){ return (2*i + 1);}
        int right(int i){ return (2*i + 2);}
        int getMax(){ return harr[0];}
        void sortt(int i);
        void insertKey(int k);
};

void MaxHeap::insertKey(int k)                   // function to insert key in the heap array
{
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;                       // insert key at the end of array
    while(i != 0 && harr[parent(i)] < harr[i])      // loop to convert array into min heap means if parent is greater than child then swap them
    {
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);  // to store left child index
    int r = right(i); // to store right child index
    int largest = i; // to store smallest child index
    if(l < heap_size && harr[l] > harr[i]) // if left child is greater than parent
        largest = l; // then change smallest variable to left child index
    if(r < heap_size && harr[r] > harr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&harr[i], &harr[largest]); // swap parent element and lesser value child
        MaxHeapify(largest); // convert them into min heap
    }
}

void MinHeap::insertKey(int k)                   // function to insert key in the heap array
{
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;                       // insert key at the end of array
    while(i != 0 && harr[parent(i)] > harr[i])      // loop to convert array into min heap means if parent is greater than child then swap them
    {
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);  // to store left child index
    int r = right(i); // to store right child index
    int smallest = i; // to store smallest child index
    if(l< heap_size && harr[l] < harr[i]) // if left child is lesser than parent
        smallest = l; // then change smallest variable to left child index
    if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap(&harr[i], &harr[smallest]); // swap parent element and lesser value child
        MinHeapify(smallest); // convert them into min heap
    }
}

int MinHeap::getmedian(){              // To get median of MinHeap array
    if(heap_size%2 == 0)                // If size of array is even then returning left median
        return harr[(heap_size/2)-1];
    return harr[heap_size/2];           // If size of array is odd then returning median
}

void MaxHeap::sortt(int c){                     // TO sort the array in O(n) time complexity
    int k = harr[0];                            // To store maximum element of array
    int cnt[k+1];                               // Array to store number of times an element occurred in array
    for(int i = 0; i <=k; i++)                  // Initialize it with zero
        cnt[i] = 0;
    for(int i = 0; i < heap_size; i++){          // Store number of occurrance
        cnt[harr[i]] += 1;
    }
    if(c == 5){                                   // To print in non-decreasing order
        cout << "(";
        for(int i = 0; i <=k; i++){
            if(cnt[i] != 0){
                for(int j = 0; j < cnt[i]; j++){
                    cout << i << ",";
                }
            }
        }
        cout << ")" << endl;
    }
    else{                                           // TO print in non-increasing order
        cout << "(";
        for(int i = k; i > 0; i--){
            if(cnt[i] != 0){
                for(int j = 0; j < cnt[i]; j++){
                    cout << i << ",";
                }
            }
        }
        cout << ")" << endl;
    }
}

int main(){
    MinHeap m;
    MaxHeap M;
    int choice = 0;
    cout << "1. Insert" << endl << "2. Find max" << endl << "3. Find min" << endl;
    cout << "4. Find median" << endl << "5. Print in non-decreasing order"<< endl << "6. Exit"<< endl;
    while(choice != 6){
        cin >> choice;
        if(choice == 1){
            int n;
            cout << "Write element to be inserted: " << endl;
            cin >> n;
            m.insertKey(n);
            M.insertKey(n);
            cout << "List in non-increasing order: ";
            M.sortt(choice);
            cout << endl;
        }
        else if(choice == 2){
            cout << "Maximum: " << M.getMax() << endl;
        }
        else if(choice == 3){
            cout << "Minimum: " << m.getMin() << endl;
        }
        else if(choice == 4){
            cout << "Median: " << m.getmedian() << endl;
        }
        else if(choice == 5){
            cout << "List in non-decreasing order: ";
            M.sortt(choice);
            cout << endl;
        }
    }
    cout << "Program exits" << endl;
}
