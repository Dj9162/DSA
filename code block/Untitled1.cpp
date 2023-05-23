#include<iostream>
using namespace std;

class Tree{
    public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Tree *insert(Tree* root, int x){
    if(!root){
        Tree* newnode = new Tree(x);
        return newnode;
    }
    if(x < root->data){
        root->left = insert(root->left, x);
    }
    if(x > root->data){
        root->right = insert(root->right, x);
    }
    return root;
}

void inorder(Tree *root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main(){

    Tree* root = NULL;
    root = insert(root, 5);
    //cout << root->data << endl;
     inorder(root);
    return 0;
}
