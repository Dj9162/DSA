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

bool Check_BST(Node* root, Node* min, Node* max)
{
    if(root == NULL)
        return true;
    if(min != NULL && root->data <= min->data)
        return false;
    if(max != NULL && root->data >= max->data)
        return false;
    bool leftValid = Check_BST(root->left,min,root);
    bool rigthValid = Check_BST(root->right,root,max);
    return leftValid and rigthValid;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);
    if(Check_BST(root,NULL,NULL))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;
    return 0;
}