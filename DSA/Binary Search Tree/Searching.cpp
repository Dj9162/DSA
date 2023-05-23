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

Node* Search(Node* root, int key)
{
    if(root == NULL) return NULL;
    if(root->data == key) return root;
    else if(key < root->data) return Search(root->left, key);
    return Search(root->right,key);

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
    Node* node = Search(root, 10);
    if(node == NULL) cout << "Not Found!!" << endl;
    else cout << "Found!" << endl;
    
    return 0;
}