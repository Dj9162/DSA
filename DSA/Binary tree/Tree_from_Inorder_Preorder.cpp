#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int search( int Inorder[], int start, int end, int curr)
{
    for (int i = start; i <=end; i++)
    {
        if( Inorder[i] == curr)
            return i;
    }
    return -1;
    
}

Node* Buildtree(int Inorder[], int Preorder[], int start, int end)
{
    if(start > end)
        return NULL;
    static int idx = 0;
    int curr = Preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if( start == end)
        return node;
    int pos = search(Inorder,start,end,curr);
    node->left = Buildtree(Inorder,Preorder,start,pos-1);
    node->right = Buildtree(Inorder,Preorder,pos+1,end);
    return node;
}


void Pre_Order(struct Node* root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    Pre_Order(root->left);
    Pre_Order(root->right);
}

int main()
{
    int Inorder[] = {4,2,5,1,6,3,7};
    int Preorder[] = {1,2,4,5,3,6,7};
    Node* root = Buildtree(Inorder,Preorder,0,6);
    Pre_Order(root);
    return 0;
}