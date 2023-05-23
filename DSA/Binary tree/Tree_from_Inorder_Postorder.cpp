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

int search(int Inorder[], int start, int end, int curr)
{
    for (int i = start; i <=end; i++)
    {
        if(Inorder[i] == curr)
            return i;
    }
    return -1;

}

Node* Buildtree(int Postorder[], int Inorder[], int start, int end)
{
    static int idx = 6;
    int curr = Postorder[idx];
    idx--;
    if( start > end)
        return NULL;
    Node* node = new Node(curr);
    if(start == end)
        return node;

    int pos = search(Inorder,start,end,curr);
    node->right = Buildtree(Postorder,Inorder,pos+1,end);
    node->left = Buildtree(Postorder,Inorder,start,pos-1);
    return node;

}

void Post_order(Node* root)
{
    if(root == NULL){ return;}
    Post_order(root->left);
    Post_order(root->right);
    cout << root->data << " ";
}

int main()
{
    int Postorder[] = {4,5,2,6,7,3,1};
    int Inorder[] = {4,2,5,1,6,3,7};
    Node* root = Buildtree(Postorder,Inorder,0,6);
    Post_order(root);
    return 0;
}
