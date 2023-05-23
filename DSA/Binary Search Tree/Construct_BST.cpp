#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* Construct_BST(int Preorder[], int* Preidx, int key, int min,int max, int n)
{
    if(*Preidx >= n)
        return NULL;
    Node* root = NULL;
    if(key > min && key < max)
    {
        root = new Node(key);
        *Preidx = *Preidx + 1;
        
        if(*Preidx < n)
        {
            root->left = Construct_BST(Preorder, Preidx, Preorder[*Preidx], min, key,n);
        }
        if(*Preidx < n)
            root->right = Construct_BST(Preorder, Preidx,Preorder[*Preidx], key, max, n);
    }
    return root;
}

void Print_Preorder(Node* root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    Print_Preorder(root->left);
    Print_Preorder(root->right);

}

int main()
{
    int Preorder[] = {7,5,4,6,8,9};
    int n = 6;
    int Preidx = 0;
    Node* root = Construct_BST(Preorder, &Preidx, Preorder[0], INT_MIN, INT_MAX, n);
    Print_Preorder(root);
    return 0;
}