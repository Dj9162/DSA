// Name: DHANRAJ KUMAR ROLL NO: 20CE10021
#include<iostream>
using namespace std;

void Scheduling(int d[], int s[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(d[s[i]] > d[s[j]]){
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int First(int l[], int d[], int s[], int n){
    int time = 0, late = 0, flag = 1;
    while(flag){
        time = 0;
        flag = 0;
        for(int i = 0; i < n; i++){
            if(time + l[s[i]] <= late + d[s[i]])
                time += l[s[i]];
            else{
                flag = 1;
                break;
            }
        }
        late++;
    }
    return late-1;
}

int Greedy(int l[], int d[],int s[],int n){
    int* C =new int[n];
    C[0] = l[s[0]];

    for(int i = 1; i < n; i++){
        C[i] = C[i-1] + l[s[i]];
    }
    int maxi = -1000;
    for(int i = 0; i < n; i++){
        if(C[i] - d[s[i]] < 0)
            continue;
        else
            maxi = max(maxi, C[i]-d[s[i]]);
    }
    return maxi;
}

int main(){

    int n;
    cout << "Write the number of jobs: ";
    cin >> n;
    int* l = new int[n];
    int* d = new int[n];

    cout << "Write the length of the jobs: ";
    for(int i = 0; i < n; i++)
        cin >> l[i];
    cout << "Write the deadline of the jobs: ";
    for(int i = 0; i < n; i++)
        cin >> d[i];
    int* s = new int[n];
    for(int i = 0; i < n; i++)
        s[i] = i;
    Scheduling(d,s,n);

    cout << "Optimal Scheduling by Greedy algorithm: ";
    for(int i =0; i <n; i++)
        cout << s[i]+1 << " ";
    cout << endl;
    cout << "Maximum lateness is: " << Greedy(l,d,s,n) << endl;
    cout << "Maximum lateness is: " << First(l,d,s,n);
}
