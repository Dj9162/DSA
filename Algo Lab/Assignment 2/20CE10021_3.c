// Name: Dhanraj Kumar  Roll no: 20CE10021  Assignment no: 2
#include<iostream>
using namespace std;

int mini(int arr[],int size){
    int m = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] <= m)
            m = arr[i];
    }
    return m;
}

int maxi(int arr[],int price[],int size,int apple){
    int m = 0;
    for(int i = 1; i < size; i++){
        if((arr[i]* price[i] >= arr[m]*price[m]) && (apple >= arr[i]))
            m = i;
    }
    return m;
}

void Recursion(int arr[], int size,int price[], int &ans[],int apple){
    if(apple < mini(arr, size))
        return;
    int max_gain = maxi(arr,price,size,apple);
    ans[i] = apple % arr[max_gain];
    apple -= ans[i];
    Recursion(arr,size,price,ans,apple);
}

int main(){
    int n = 0, m = 0;
    cout << "Write the number of apples that Ramu has: ";
    cin >> n;
    cout << "Write the number of buyers: ";
    cin >> m;
    int fam = new int[m];
    cout << "Write family sizes: " << endl;
    for(int i = 0; i < m; i++)
        cin >> fam[i];
    int price = new int[m];
    cout << "Write prices:" << endl;
    for(int i = 0; i < m; i++)
        cin >> price[i];
    int ans = new int[m];
    for(int i = 0; i < m; i++)
        ans[i] = 0;
    cout << "Output of recursive implementation" << endl;
    Recursion(fam,m,price,ans,n);
    for(int i = 0; i < m; i++)
        cout << ans[i] << " ";

}
