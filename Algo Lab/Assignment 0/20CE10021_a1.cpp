#include<iostream>
using namespace std;


class Stack {
public:
    int top = -1;
    int s[1000];

    Stack() { top = -1;}
    void push(int x);
    void pop();
    int Top();
};

void Stack::push(int x)
{
    s[++top] = x;
}

void Stack::pop()
{
    --top;
}
int Stack::Top(){
    return s[top];
}

bool algo1(int arr[], int n){
    int x, y, z;
   int i, j, k, index = 0;

   for (x=1; x<=n; x++) {
      for (y=x+1; y<=n; y++) {
         for (z=y+1; z<=n; z++) {
            i = j = k = -1;
            for (index=0; index < n; index++) {
               if (arr[index] == x) i = index;
               else if (arr[index] == y) j = index;
               else if (arr[index] == z) k = index;
            }
            if ((i < k) && (k < j)) return false;
         }
      }
   }
   return true;
}

bool algo2 ( int arr[], int n )
{
   int x, y, z,i,j,k;

   for (i=0; i<n; ++i) {
      x = arr[i];
      for (j=i+1; j<n; ++j) {
         y = arr[j];
         for (k=j+1; k<n; ++k) {
            z = arr[k];
            if ((x < z) && (z < y)) return false;
         }
      }
   }
   return true;
}

bool algo3 ( int arr[], int n )
{
   int x, y,i,j;

   for (i=0; i<n; i++) {
      x = arr[i];
      y = x;
      for (j=i+1; j<n; j++) {
            int z = arr[j];
         if (z > x) {
            if (z < y) return 0;
            y = arr[j];
         }
      }
   }
   return 1;
}

bool algo4 ( int arr[], int n )
{
   class Stack S;
   int i, a = 1,cnt = 0,x,y,k,l;
   for (i=0; i<n; ++i) {
      while (a <= arr[i]) {
         ++a;
      }
      S.push(i);
      if (S.top == -1) return false;
      if (S.Top() != arr[i]) return false;
      if(cnt == 2){
        x = arr[S.Top()];
        k = S.Top();
        S.pop();
        y = arr[S.Top()];
        l = S.Top();
        for(int b = k+1; b < l; b++){
            if((x < arr[b]) && (y < arr[b]) )
                return false;
        }
      }
      cnt++;
      S.pop();
   }
   return true;
}

int main(){
    int n;
    printf("Enter the size Of array: ");
    cin >> n;
    int *arr = new int[n];
    printf("Enter elements of array: ");
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(algo1(arr,n))
        cout << "Musical" << endl;
    else
        cout << "Non Musical" << endl;
    if(algo2(arr,n))
        cout << "Musical" << endl;
    else
        cout << "Non Musical" << endl;
    if(algo3(arr,n))
        cout << "Musical" << endl;
    else
        cout << "Non Musical" << endl;
    if(algo4(arr,n))
        cout << "Musical" << endl;
    else
        cout << "Non Musical" << endl;
}
