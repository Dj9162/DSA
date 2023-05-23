// Name: Dhanraj Kumar Roll no: 20CE10021
#include<iostream>
using namespace std;

struct node{
    int data;
    node* left, *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* Build_BST(node* root, int val)            // Function to build binary search tree
{
    if(root == NULL)                             // If tree is empty then make first element as root node and return
        return new node(val);
    if(val < root->data)                          // If value you want to enter is less than root node then traverse in left subtree and find its place and insert
    {
        root->left = Build_BST(root->left, val);
    }
    else if(val > root->data)                                         // If value you want to enter is greater than root node then traverse in right subtree and find its place and insert
    {
        root->right = Build_BST(root->right, val);
    }
    else{
        cout << "Duplicate values can't be stored!!";
    }
    return root;

}

node* Inorder_predecessor(node* root){             // To get Inorder precedecessor from left subtree of node
    node* curr = root;
    while(curr && curr->right != NULL){            // As we know Inorder precedecessor is the largest element in left subtree and largest element will always lie in rightmost part
        curr = curr->right;
    }
    return curr;
}

node* Inorder_Succesor(node* root)               // To get Inorder Succesor from right subtree of node
{
    node* curr = root;
    while (curr && curr->left != NULL)            // As we know Inorder Succesor is the smallest element in right subtree and smallest element will always lie in leftmost part
    {
        curr = curr->left;
    }
    return curr;
}

node* Delete_Key(node* root, int key)         // Function to delete a known key
{                                               // First find key which you want to delete
    if(key < root->data)                         // If it is less than root then find in left subtree
    root->left = Delete_Key(root->left,key);
    else if(key > root->data)                     // If it is greater than root then find in right subtree
    root->right = Delete_Key(root->right,key);
    else                                           // If element is found
    {
        if(root->left == NULL)                     // If there is no left node then exchange right node with root and delete
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)             // If there is no right node then exchange left node with root and delete
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = Inorder_predecessor(root->left);     // If it has both child then find largest element from left subtree and exchange with that and delete
        if( temp == NULL){
            temp = Inorder_Succesor(root->right);
            root->data = temp->data;
            root->right = Delete_Key(root->right, temp->data);
        }
        else{
            root->data = temp->data;
            root->left = Delete_Key(root->left, temp->data);
        }
    }
    return root;

}

void Print_Preorder(node* root)                  // To print tree in Preorder traversal means first print root data then traverse left and then traverse right
{
    if(root == NULL) return;
    cout << root->data << " ";
    Print_Preorder(root->left);
    Print_Preorder(root->right);

}

int max_height(node * root) {                         // TO find the maximum height of tree
    if (root == NULL)                                 // Let if there is no element in tree then its height be -1;
      return -1;
    else {

      int left_height = max_height(root -> left);       // Find maximum height of left subtree
      int right_height = max_height(root -> right);     // Find maximum height of right subtree


      return max(left_height+1, right_height+1);        // returning maximum height of left and right subtree
    }
}

// Get Balance factor of node N
int getBalanceFactor(node * n) {
    if (n == NULL)
      return -1;
    return max_height(n -> left) - max_height(n -> right);
}

node *rightRotate(node *temp) {      // To do single rotation function at node in right direction if height of left subtree gets greater than height of right subtree
    node *temp1 = temp-> left;
    node * temp2 = temp1 -> right;


    temp1 -> right = temp;
    temp-> left = temp2;

    return temp1;
}

node *leftRotate(node *temp) {         // To do single rotation function at node in left direction if height of right subtree gets greater than height of left subtree
    node *temp1 = temp-> right;
    node *temp2 = temp1-> left;

    // Perform rotation
    temp1 -> left = temp;
    temp -> right = temp2;

    return temp1;
}

node *balance(node *root, node* key) {              // To balance the BST and convert it into AVL tree
    if (root == NULL) {
      root = key;
      return root;
    }

    if (key->data < root->data) {
      root->left = balance(root->left, key);
    }
    else if (key->data > root->data) {
      root->right = balance(root->right, key);
    }
    int bf = getBalanceFactor(root);
    // Left Left Case
    if (bf > 1 && key -> data < root -> left -> data)
      return rightRotate(root);

    // Right Right Case
    else if (bf < -1 && key -> data > root -> right -> data)
      return leftRotate(root);

    // Double rotation
    else if (bf < -1 && key -> data < root -> right -> data) {
      root -> right = rightRotate(root -> right);
      return leftRotate(root);
    }
    // Double rotation
    else if (bf > 1 && key -> data > root -> left -> data) {
      root -> left = leftRotate(root -> left);
      return rightRotate(root);
    }

    /* return the (unchanged) node pointer */
    return root;

  }


void Preorder_array(node* root, int arr[],int index){   // To get Preorder array
    if(root == NULL)
        return;
    static int idx = index;
    arr[idx++] = root->data;
    Preorder_array(root->left,arr,index);
    Preorder_array(root->right,arr,index);
}

void Inorder_array(node* root, int arr[],int index){             // To get Inorder array
    if(root == NULL)
        return;
    static int idx = index;
    Preorder_array(root->left,arr,index);
    arr[idx++] = root->data;
    Preorder_array(root->right,arr,index);
}

int main(){
    cout << "1. insert" << endl << "2. delete" << endl << "3. make tree balanced (AVL tree based method)." << endl;
    cout << "4. make tree balanced faster" << endl << "5. exit" << endl;
    int choice = 1, temp = 0;
    node *root = NULL;
    while(choice != 5){
        cin >> choice;
        if( choice == 1){
            int n;
            cout << "Write key to be inserted: ";
            cin >> n;
            if(temp == 0){
                root = Build_BST(root,n);
                temp++;
            }
            else{
                Build_BST(root,n);
                temp++;
            }
            cout << "Pre-order Traversal: ";
            Print_Preorder(root);
            cout << endl;
        }
        else if( choice == 2){
            int n;
            cout << "Write key to be deleted: ";
            cin >> n;
            Delete_Key(root,n);
            temp--;
            cout << "Pre-order Traversal: ";
            Print_Preorder(root);
            cout << endl;
        }
        else if( choice == 3){

            int* arr = new int[temp];
            Preorder_array(root,arr,0);
            root = NULL;
            for(int i = 0; i < temp ; i++){
                node* new_node = new node(arr[i]);
                root = balance(root,new_node);
            }
            cout << "Pre-order traversal of tree after balancing with AVL tree based method: ";
            Print_Preorder(root);
            cout << endl;
            delete[] arr;
        }
//        else if( choice == 4){   // Make AVL using INorder array using Divide and conquer as all elemnts of left of any element will always be in left subtree and vice versa
//
//            int* arr = new int[temp];
//            Inorder_array(root,arr,0);
//            root = NULL;
//            for(int i = 0; i < temp ; i++){
//                node* new_node = new node(arr[i]);
//                root = balance(root,new_node);
//            }
//            cout << "Pre-order traversal of tree after balancing with AVL tree based method: ";
//            Print_Preorder(root);
//            cout << endl;
//            delete[] arr;
//        }


    }
    cout << "Program exit!!" << endl;
}
