#include <bits/stdc++.h>
using namespace std;
const int k = 2;

struct Node{
    int point[k];
    Node *left, *right;
};

struct Node* newNode(int arr[])
{
    struct Node* temp = new Node;
    for(int i = 0; i < k; i++)
        temp->point[i] = arr[i];
    
    temp->left = temp->right = NULL;
    return temp;
}

Node* insertRec(Node* root, int point[], unsigned depth)
{
    if(root == NULL)
        return newNode(point);

    unsigned cd = depth % k;

    if(point[cd] < (root->point[cd]))
        root->left = insertRec(root->left,point,depth+1);
    else
        root->right = insertRec(root->right,point,depth+1);
    return root;

}

Node* insert(Node* root, int point[])
{
    return insertRec(root,point,0);
}

bool arePointsSame(int Point1[], int Point2[])
{
    for(int i= 0; i < k ; i++)
        if(Point1[i] != Point2[i])
            return false;
    return true;
}

int min( int a, int b, int c)
{
    return min(a,min(b,c));
}

int findMinRec(Node* root, int d, unsigned depth)
{
    if(root == NULL)
        return INT_MAX;
    
    unsigned cd = depth % k;

    if( cd == d)
    {
        if(root->left == NULL)
            return root->point[d];
        return min(root->point[cd],findMinRec(root->left,d,depth+1));
    }

    return min(findMinRec(root->left,d,depth+1),findMinRec(root->right,d,depth+1),root->point[cd]);
}

int findMin(Node* root, int d)
{
    return findMinRec(root,d,0);
}

bool searchRec(Node* root, int point[], unsigned depth)
{
    if(root == NULL)
        return false;
    if(arePointsSame(root->point,point))
        return true;

    unsigned cd = depth % k;
    if(point[cd] < (root->point[cd]))
        return searchRec(root->left,point,depth+1);
    return searchRec(root->right,point,depth+1);
}

bool search(Node* root, int point[])
{
    return searchRec(root,point,0);
}

void copyPoint(int p1[], int p2[])
{
    for(int i = 0; i<k; i++)
        p1[i] = p2[i];
}

Node* deleteNodeRec(Node* root, int point[], int depth)
{
    if(root == NULL)
        return NULL;

    int cd = depth % k;

    if(arePointsSame(root->point,point))
    {
        if(root->right != NULL)
        {
            Node* min = findMin(root->right,cd);
            copyPoint(root->point,min->point);
            root->right = deleteNodeRec(root->right,min->point,depth+1);
        }
        else if(root->left != NULL)
        {
            Node* min = findMin(root->left,cd);
            copyPoint(root->point,min->point);
            root->right = deleteNodeRec(root->left,min->point,depth+1);
        }
        else
        {
            delete root;
            return NULL;
        }
        return root;
    }

    if(point[cd] < root->point[cd])
        root->left = deleteNodeRec(root->left,point,depth+1)
    else
        root->right = deleteNodeRec(root->right,point,depth+1);
    return root;
}

Node* deleteNode(Node* root, int point[])
{
    return deleteNodeRec(root,point,0);
}

int main()
{
    struct Node* root = NULL;
    int points[][k] = {{3,6},{17,15},{13,15},{6,12},{9,1},{2,7},{10,19}};
    int n = sizeof(points)/sizeof(points[0]);

    for(int i = 0; i < n; i++)
        root = insert(root,points[i]);
    int point1[] = {10,19};
    (search(root,point1))? cout << "Found\n" : cout << "Not Found\n";
    int point2[] = {12,19};
    (search(root,point2))? cout << "Found\n" : cout << "Not Found\n";  

    cout <<"Minimum of 0'th dimension is " << findMin(root,0) << endl;  
    cout <<"Minimum of 1'th dimension is " << findMin(root,1) << endl; 

    return 0;
}