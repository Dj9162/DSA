#include<iostream>
using namespace std;

struct Tree{
    int data, h;
    Tree* left, *right;

    Tree(int x)
    {
        data = x;
        h = 0;
        left = NULL;
        right = NULL;
    }
};

Tree* insert(Tree* root, int val)
{
    if(!root)
        return new Tree(val);
    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;

}

void Inorder(Tree* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Tree* root){
    if(!root)   return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void print__tree(Tree* root){
    cout << endl << endl;
    cout << "Traversals of created BST" << endl;
    cout << "Preorder   : ";
    Preorder(root);
    cout << endl;
    cout << "Inorder    : ";
    Inorder(root);
}

int height(Tree* r) {
    if (r == NULL)
        return -1;

    /* compute the height of each subtree */
    int lheight = height(r -> left);
    int rheight = height(r -> right);

    /* use the larger one */
    if (lheight > rheight)
        return (lheight + 1);
    else return (rheight + 1);

}

void node_height(Tree* root, int* m_height){
    if(root == NULL) return;
    node_height(root->left, m_height);
    root->h = height(root);
    if(*m_height < root->h)
        *m_height = root->h;
    node_height(root->right, m_height);
}

void print_hrange(Tree* root, int k, int l){
    if(root == NULL) return;
    print_hrange(root->left, k, l);

    if(root->h >= k && root->h <= l)
        cout << "(" << root->data << ":" << root->h << ") ";
    print_hrange(root->right, k, l);
}

int main(){
    Tree* root = NULL;
    int n = 0, a = 0;
    cout << "n = ";
    cin >> n;

    cout << "Enter keys to insert" << endl;
    for(int i = 0; i < n; i++){
        cin >> a;
        root = insert(root, a);
    }
    print__tree(root);
    int m_height = 0;
    node_height(root, &m_height);
    cout << endl << "Heights of all nodes computed." << endl;
    cout << "   Maximum height: " << m_height << endl;
    int k = 0, l = 0;
    cout << "k = ";
    cin >> k;
    cout << "l = ";
    cin >> l;

    cout << "key:height for all nodes in the height range [" << k << " ," << l << "]" << endl;
    print_hrange(root, k, l);

    return 0;
}
