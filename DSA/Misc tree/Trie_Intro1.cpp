#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;

struct Trienode{
    struct Trienode* children[ALPHABET_SIZE];
    bool isEndofWord;
};

struct Trienode* getNode(void)
{
    struct Trienode* pNode = new Trienode;
    pNode->isEndofWord = false;
    for(int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct Trienode* root,string key)
{
    struct Trienode* pCrawl = root;

    for(int i = 0; i <key.length() ;i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = true;
}

bool search(struct Trienode* root, string key)
{
    struct Trienode* pCrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndofWord);
}

bool isEmpty(Trienode* root)
{
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i])
            return false;
    }
    return true;
}

Trienode* remove(Trienode* root, string key, int depth = 0)
{
    if(!root)
        return NULL;

    if(depth == key.size())
    {
        if(root->isEndofWord)
            root->isEndofWord = false;

        if(isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index],key,depth+1);
    if(isEmpty(root) && root->isEndofWord == false){
        delete root;
        root = NULL;
    }
    return root;
}

int main()
{
    string keys[] = { "the", "a", "there","answer","any","by","bye","their","hero","heroplane"};
    int n = sizeof(keys) / sizeof(keys[0]);
    struct Trienode* root = getNode();
    for(int i = 0; i<n; i++)
        insert(root,keys[i]);
    search(root,"the")? cout <<"Yes\n" : cout <<"No\n";
    search(root,"these")? cout <<"Yes\n" : cout <<"No\n";
    search(root,"heroplane")? cout <<"Yes\n" : cout <<"No\n";
    remove(root,"heroplane");
    search(root,"hero")? cout <<"Yes\n" : cout <<"No\n";
    search(root,"heroplane")? cout <<"Yes\n" : cout <<"No\n";

    return 0;
}