#include<iostream>
using namespace std;

class Maxheap{
    public:
    int arr[100];
    int idx;

    Maxheap(){
        idx = 0;
    }

    void insert(int val){
        idx++;
        arr[idx] = val;

        int t = idx;
        while(t != 1){
            int p = t/2;

            if(arr[t] > arr[p]){
                swap(arr[t], arr[p]);
                t = p;
            }
            else
                return;
        }
    }

    void delete_key(){
        arr[1] = arr[idx];
        idx--;

        int i = 1;
        while( i <= idx){
            int l = 2*i;
            int r = 2*i + 1;

            if(l < idx && r < idx){
                if(arr[l] < arr[r]){
                    swap(arr[r], arr[i]);
                    i = r;
                }
                else{
                    swap(arr[l], arr[i]);
                    i = l;
                }
            }
            else if(l < idx && arr[i] < arr[l]){
                swap(arr[l], arr[i]);
                i = l;
            }
            else if(r < idx && arr[i] < arr[r]){
                swap(arr[i], arr[r]);
                i = r;
            }
            else
                return;
        }
    }



    void print(){
        for(int i = 1; i <= idx; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void Heapify(int i, int harr[], int n){
        int l = 2*i;
        int r = 2*i + 1;
        int largest = i;
        if(l < n && harr[largest] < harr[l])
            largest = l;
        if(r < n && harr[largest] < harr[r])
            largest = r;
        if( largest != i){
            swap(harr[largest], harr[i]);
            Heapify(largest, harr, n);
        }
    }

int main(){
    Maxheap h;
    h.insert(5);
    h.insert(15);
    h.insert(4);
    h.insert(10);
    h.insert(12);
    h.insert(16);
    h.print();
    h.delete_key();
    h.print();
    int harr[] = {-1,4,6,3,5,2,8,9};
    for(int i = 8/2; i >= 1; i--){
        Heapify(i, harr, 8);
    }
    for(auto i: harr)
        cout << i << " ";
    cout << endl;
    return 0;
}
