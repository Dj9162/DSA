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

Node* Inorder_Succesor(Node* root)
{
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node* Delete_BST(Node* root, int key)
{
    if(key < root->data)
    root->left = Delete_BST(root->left,key);
    else if(key > root->data)
    root->right = Delete_BST(root->right,key);
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = Inorder_Succesor(root->right);
        root->data = temp->data;
        root->right = Delete_BST(root->right, temp->data);
        
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
    Inorder(root);
    cout << endl;
    root = Delete_BST(root, 5);
    Inorder(root);
    cout << endl;
    
    return 0;
}