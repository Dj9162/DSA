#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    char data;
    Trie *children[26];
    int w_end;

    Trie(char c){
        this->data = c;

        for(int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->w_end = 0;
    }

};

class TrieNode{
    Trie *root = new Trie('\0');

public:
    void insert(string s, Trie* root){
        if(s.length() == 0){
            root->w_end++;
            return;
        }


        int idx = s[0] - 'a';

        Trie *temp;
        if(root->children[idx] == NULL){
            temp = new Trie(s[0]);
            root->children[idx] = temp;
        }
        else{
            temp = root->children[idx];

        }
        insert(s.substr(1), temp);
    }

    void insertUtil(string s){
        insert(s, root);
    }

    int search(string s, Trie* root){
        if(s.length() == 0){
            return s.length();
        }

        int idx = s[0] - 'a';

        if(root->children[idx] == NULL){
            return s.length();
        }
        return search(s.substr(1), root->children[idx]);
    }

    int searchUtil(string s){
        return search(s, root);
    }

    void remove(string s, Trie* root){

        if(s.length() == 0 && root->w_end != 0){
            root->w_end--;
        }

        int idx = s[0] - 'a';

        remove(s.substr(1), root->children[idx]);
    }

    void removeUtil(string s){
        remove(s, root);
    }

};

int main(){
    TrieNode T;
    T.insertUtil("geeksforgeeks");
    string arr[] = {"geeks", "geek", "geezer"};

    int m_ans = INT_MAX;
    for(int i = 0; i < 3; i++){

        int t = arr[i].length() - T.searchUtil(arr[i]);
        m_ans = min( m_ans, t);

    }
    cout << m_ans << endl;

    return 0;
}
