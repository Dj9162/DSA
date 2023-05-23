#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int capacity;
    int* arr;
    int heap_size;
    public:
        MinHeap(int capacity);
        void MinHeapify(int );
        int parent(int i){ return (i-1)/2;}
        int left(int i){ return (2*i + 1);}
        int right(int i){ return (2*i + 2);}
        int extractMin();
        int getMin(){ return arr[0];}
        void insertKey(int k);
        bool empty();
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap+1;
    arr = new int[cap];
}

bool MinHeap::empty(){
    if(heap_size == 0)
        return 0;
    return 1;
}

void MinHeap::insertKey(int k)                   // function to insert key in the heap array
{
    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;                       // insert key at the end of array
    while(i != 0 && arr[parent(i)] > arr[i])      // loop to convert array into min heap means if parent is greater than child then swap them
    {
        swap(&arr[i],&arr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin() // top element of min heap is always lesser
{
    if(heap_size < 0)
        return INT_MAX;
    if(heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }
    int min_ele = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    MinHeapify(0); // convert the left elements into min heap
    return min_ele;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);  // to store left child index
    int r = right(i); // to store right child index
    int smallest = i; // to store smallest child index
    if(l< heap_size && arr[l] < arr[i]) // if left child is lesser than parent
        smallest = l; // then change smallest variable to left child index
    if(r < heap_size && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap(&arr[i], &arr[smallest]); // swap parent element and lesser value child
        MinHeapify(smallest); // convert them into min heap
    }
}

int main()
{
    int n, cnt = 1;
    cout << "n = ";
    cin >> n;
    MinHeap H1(n);                  // Making H1 min heap
    MinHeap H2(n);                  // Making H2 min heap
    for(int i = 1; i <= n; i++){     // Initializing H1 and H2
        H1.insertKey(i+1);
        H2.insertKey((i*i*i)+1);
    }
    int a = 1,b = 1,c = 1, d = 1;
    while((H1.empty() != 0) && (H2.empty() != 0) && (a <= n && c <= n)){
        if(H1.getMin() < H2.getMin()){                 // If minimum element of H1 is lesser then remove it and insert larger number
            H1.extractMin();
            if(b < n){
                b++;
                H1.insertKey(a+(b)*(b));
            }
            else{
                b = 1;
                a++;
            }
        }
        else if(H1.getMin() > H2.getMin()){       // If minimum element of H2 is lesser then remove it and insert larger number
            H2.extractMin();
            if(d < n){
                d++;
                H1.insertKey(c*c*c+ d*d*d*d);
            }
            else{
                d = 1;
                c++;
            }
        }
        else{                                   // If min of both Heap is equal then remove both and print values of a,b,c and d and insert next element in both heap
            H1.extractMin();
            H2.extractMin();
            cnt++;
            cout << a << " " << b << " " << c << " " << d << endl;
            if(b < n){
                b++;
                H1.insertKey(a+(b)*(b));
            }
            else{
                b = 1;
                a++;
            }
            if(d < n){
                d++;
                H1.insertKey(c*c*c + d*d*d*d);
            }
            else{
                d = 1;
                c++;
            }
        }

    }
    cout << "Total number of solution: " << cnt << endl;
    return 0;
}
