// Name: DHANRAJ KUMAR   Roll no: 20CE10021     Test: 1
#include<iostream>
using namespace std;

void Scheduling(int e[], int index[], int n){      // Function to sort index array in ascending order by refrense of ending angle means only sorting index of ending angle with the help of ending angle value
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(e[index[i]] > e[index[j]]){             // Comparing values of ending angles and changing the index array
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}

void greedy(int s[], int e[], int index[],int n, int Ans[]){   // Function to store all required answer index in A;
    Ans[0] = index[0];                                         // First index is always included as it has lowest ending angle
    int k = 0,i = 1,j = 1;

    while( j < n){
        if(s[index[j]] > e[index[k]]){                           // checking starting angle of current object and ending angle of previous object it should be greater.
            Ans[i++] = index[j];
            k = j;                                       // If satisfied if condition then change value of k to j.
        }
        j++;
    }
} // Time complexity: O(n)

int main(){
    int n;
    cout << "Write the number of objects: ";
    cin >> n;                                                                  // To store number of objects inputed by user
    cout << "Write the start and end angles of " << n << "objects."<< endl;
    int* s = new int[n];                                                       // To store start angle of objects
    int* e = new int[n];                                                       // To store end angle of objects
    for(int i = 0; i < n; i++){
        cout << "Start = ";
        cin >> s[i];
        cout << "End = ";
        cin >> e[i];
    }
    int* index = new int[n];                                                       // To store initial indexes of both start and end angle
    for(int i = 0; i < n; i++)
        index[i] = i;
    Scheduling(e,index,n);
    int* Ans = new int[n];                                                      // To store indexes of answer
    for(int i = 0; i < n; i++)                                                // Initializing all with -1;
        Ans[i] = -1;
    greedy(s,e,index,n,Ans);
    cout << "Objects selected:" << endl;
    for(int i = 0; i < n; i++){
        if(Ans[i] != -1){                                                      // Checking value of A if there is -1 then that is not our required answer
            cout << "Start = " << s[Ans[i]] << " " << "End = " << e[Ans[i]] << endl;
        }
    }
    return 0;
}
