#include<iostream>
#include<vector>
#include<set>
using namespace std;

//void print_a(char str[], int index,int n,set<string>& ans){
//    if(index >= n){
//
//        if(str[0] == '|' || str[n-1] == '|')
//            return;
//        for(int j = 0; j < n-1; j++){
//            if(str[j] == '|' && str[j+1] == '|')
//                return;
//        }
//        ans.insert(str);
//
//        return;
//    }
//    for(int i = index; i < n; i++){
//        swap(str[index],str[i]);
//        print_a(str,index+1,n,ans);
//        swap(str[index],str[i]);
//    }
//}

bool shouldSwap(char str[],int start,int curr){
    for(int i = start; i < curr; i++){
        if(str[i] == str[curr])
            return 0;
    }
    return 1;
}

void print_a(char str[], int index,int n,int& cnt){
    if(index >= n){

        if(str[0] == '|' || str[n-1] == '|')
            return;
        for(int j = 0; j < n-1; j++){
            if(str[j] == '|' && str[j+1] == '|')
                return;
        }

        cout << str << endl;
        cnt++;
        return;
    }
    for(int i = index; i < n; i++){
        bool check = shouldSwap(str,index,i);
        if(check){
        swap(str[index],str[i]);
        print_a(str,index+1,n,cnt);
        swap(str[index],str[i]);}
    }
}

void print_b(char str[], int index,int n, set<string>& ans1){
    if(index >= n){

        if((str[0] == '|' && str[1] == '|') || (str[n-1] == '|' && str[n-2] == '|'))
            return;

        for(int j = 0; j < n-2; j++){
            if(str[j] == '|' && str[j+1] == '|' && str[j+2] == '|')
                return;
        }
        ans1.insert(str);

        return;
    }
    for(int i = index; i < n; i++){
        swap(str[index],str[i]);
        print_b(str,index+1,n,ans1);
        swap(str[index],str[i]);
    }
}

//void print_b(char str[], int index,int n,char *ans[][40],int& cnt){
//    if(index >= n){
//
//        if((str[0] == '|' && str[1] == '|') || (str[n-1] == '|' && str[n-2] == '|'))
//            return;
//
//        for(int j = 0; j < n-2; j++){
//            if(str[j] == '|' && str[j+1] == '|' && str[j+2] == '|')
//                return;
//        }
//          for(int i = 0; i < cnt; i++){
//            for(int j = 0; j < n; j++)
//                if(*ans[i][j] == str[j])
//                    return;
//        }
//        for(int i = 0; i < n; i++)
//            *ans[cnt][i] = str[i];
//        cnt++;
//        return;
//
//    }
//    for(int i = index; i < n; i++){
//        swap(str[index],str[i]);
//        print_b(str,index+1,n,ans1);
//        swap(str[index],str[i]);
//    }
//}

int main(){
    int n = 0,m = 0,cnt = 0;
    char str[40];
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    //char* ans[40][40], ans1[100][100];
    set<string> ans;
    set<string> ans1;
    for(int i = 0; i < n;i++)
        str[i] = 'S';
    for(int j = n; j < n+m-1; j++)
        str[j] = '|';
    str[n+m-1] = '\0';
    print_a(str,0,n+m-1,cnt);
    cout << cnt ;
    //cout << cnt << endl;
    //print_a(str,0,n+m-1,ans);
//    for(string s : ans)
//       cout << s << endl;
//    cout << "Total number of distributions = " << ans.size() << endl;
//    print_b(str,0,n+m-1,ans1);
//    print_b(str,0,n+m-1,ans1);
//    for(string s : ans1)
//        cout << s << endl;
//    cout << "Total number of distributions = " << ans1.size() << endl;
    return 0;
}
