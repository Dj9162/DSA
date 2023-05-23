#include<iostream>
using namespace std;
int possible(int l, int n, int ar[],int m[5][5]){
    int dp[n][n][5];
    //We use a 3 dimensional dp array where dp[i][j][k] is 1 if it is possible to get the (k+1)th sauce by mixing the 
    //the sequence of sauces from the ith to the jth index (i.e. ar[i, i+1, i+2 ... j-1, j]) and 0 otherwise
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int a=0;a<5;a++){
                dp[i][j][a]=0;     
                //We initialise all the indexes with 0
            }
        }
        //A sequence of one sauce will always yield the same sauce, so we initialise all 1 length sequences with 1
        dp[i][i][ar[i]-1]=1;
    }
    for(int len=2;len<=n;len++){
        //We iterate over the length of the sequence
        for(int i=0;i<n-len+1;i++){
            //We iterate over the first index of the sequence
            int j=i+len-1;
            //The second index will be j when the length is len
            for(int k=i;k<j;k++){
                //We iterate over all k between i and j
                for(int a=0;a<5;a++){
                    for(int b=0;b<5;b++){
                        if(dp[i][k][a]==1 && dp[k+1][j][b]==1)
                            dp[i][j][m[a][b]-1] = 1;
                        //We will check if we can form a from the (i to k index) and b from the (k+1 to j index)
                        //If we can then we can also form m[a][b] from the (i to j index) 
                    }
                }
            }
        }
    }
    //Return 1 if we can form the lth sauce from the entire sequence and 0 otherwise
    return dp[0][n-1][l-1];
}
void countways(int n,int ar[], int m[5][5]){
    long long dp[n][n][5];
    //We use a 3 dimensional dp array where dp[i][j][k] represents the number of ways to get the (k+1)th sauce by mixing the 
    //the sequence of sauces from the ith to the jth index (i.e. ar[i, i+1, i+2 ... j-1, j])
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int a=0;a<5;a++){
                dp[i][j][a]=0;    
                //We initialise all the indexes with 0 
            }
        }
        //A sequence of one sauce will always yield the same sauce, so we initialise all 1 length sequence with 1
        dp[i][i][ar[i]-1]=1;
    }
    for(int len=2;len<=n;len++){
        //We iterate over the length of the sequence
        for(int i=0;i<n-len+1;i++){
            //We iterate over the first index of the sequence
            int j=i+len-1;
            //The second index will be j when the length is len
            for(int k=i;k<j;k++){
                //We iterate over all k between i and j
                for(int a=0;a<5;a++){
                    for(int b=0;b<5;b++){
                        dp[i][j][m[a][b]-1] += dp[i][k][a]*dp[k+1][j][b];
                        //The number of ways to form m[a][b] from the (i to j index) will be the number of ways we can 
                        //form a from the (i to k index) multiplied with the number of ways we can form b from the (k+1 to j index)
                    }
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        //Print the number of ways we can form the ith sauce from the entire sequence
        cout<<i+1<<": "<<dp[0][n-1][i]<<endl;
    }
}
int main()
{
    
    int m[5][5],n=0,ar[55];
    cout<<"Enter M:"<<endl;
    //Input for M
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>m[i][j];
        }
    }
    cout<<"\nEnter string: "<<endl;
    char* s = new char[55];
    //Input for string
    cin>>s;
    for(int i=0;i<55;i++){
        if(s[i]=='\0') break;
        ar[n++]=(s[i]-'0');
    }
    //We convert the string to an integer array of size n for convenience
    cout<<endl;
    for(int i=1;i<=5;i++){
        cout<<i<<": "<<(possible(i,n,ar,m) ? "Possible" : "Not Possible")<<endl;
    }

    cout<<"\nNumber of ways in which mixing "<<s<<" results in"<<endl;
    countways(n,ar,m);
    return 0;
} 