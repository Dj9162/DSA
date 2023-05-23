#include <iostream>
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
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    /*         1
            /    \
           2      3
          / \    / \
         N   N  N   N
    
    */
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    /*               1
                  /     \
                 2       3
               /   \    /  \
              4     5   N   6
    */

    return 0;
}