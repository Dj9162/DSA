#include <iostream>
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

Node* Build_BST(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);
    if(val < root->data)
    {
        root->left = Build_BST(root->left, val);
    }
    else
    {
        root->right = Build_BST(root->right, val);
    }
    return root;

}

void Inorder(Node* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root){
    if(!root)   return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = Build_BST(root,5);
    Build_BST(root, 1);
    Build_BST(root, 3);
    Build_BST(root, 4);
    Build_BST(root, 2);
    Build_BST(root, 7);
    Inorder(root);
    cout << endl;
    Preorder(root);

    return 0;
}
