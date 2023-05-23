#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right, *parent;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node * rightRotate(Node * y) {
    Node * x = y -> left;
    Node * T2 = x -> right;

    // Perform rotation  
    x -> right = y;
    y -> left = T2;

    return x;
  }

  Node * leftRotate(Node * x) {
    Node * y = x -> right;
    Node * T2 = y -> left;

    // Perform rotation  
    y -> left = x;
    x -> right = T2;

    return y;
  }

Node* Build_BST(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);
    if(val < root->data)
    {
        root->left = Build_BST(root->left, val);
        root->left->parent = root;
    }
    else
    {
        root->right = Build_BST(root->right, val);
        root->left->parent = root;
    }
    return root;

}

void check(Node* root, Node* temp){
    if(root == temp)
        return;
    
    if(temp->parent->right == temp && temp->parent->parent->left == temp->parent){
        Node* p = temp->parent;
        temp->parent = leftRotate(temp->parent);
        
        temp->parent = p->parent;
        p->parent = temp;
        if(temp->left)
            temp->left->parent = p;
        Node* g = temp->parent;
        temp->parent = rightRotate(temp->parent);
        g->parent = temp;
        if(temp->right)
            temp->right->parent = g;
    }
}

void Preorder(Node* root){
    if(!root)   return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int main(){
    Node* root = NULL;
    root = Build_BST(root,5);

    return 0;
}