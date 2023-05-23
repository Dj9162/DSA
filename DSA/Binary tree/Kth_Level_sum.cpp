#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

int Kth_Level_sum(Node* root, int val)
{
    if( root == NULL) return 0;
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    int sum = 0,level = 0;
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            if(level == val)
                sum += node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right); 
        }
        else if(!q.empty())
        {
            level++;
            q.push(NULL);
        }
    }
    return sum;
    
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << Kth_Level_sum(root,2) << endl;
    return 0;
}