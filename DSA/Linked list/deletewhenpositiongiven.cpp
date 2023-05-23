#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int a)
        : data(a){}
};

void del_ele( Node** n, int pos)
{
    if( *n == NULL)           // Check whether the complete list is empty or not if :then just return
        return;
    Node* temp = *n;         // storing the value of head in new node named temp
    if ( pos == 0)            // Check whether the given position is first or not if then shift the head to next element and delete first element
    {
        *n = temp->next;
        free(temp);            // deleting temp;
        return;
    }                         // if given position is not first then 
    for (int i = 0; i < pos-1 && temp != NULL; i++) // Loop to find previous element of required element and check whether the given position is greater than no. of elements in list
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)      // If given position is greater than no. of elements in list
    {  
        cout << " Invalid Input !!" << endl;
        return;
    }
    Node* new_node = temp->next->next;        // storing the address of next element of required element in new_node
    free (temp->next);                  // deleting required node
    temp->next = new_node;                 // giving new_node in next of temp node
    
}

void print( Node* n)
{
    if( n == NULL)
        return;
    cout << n->data << " ";
    print( n->next);
    cout << "\n";
}
int main()
{
    Node* head = new Node(0);
    Node* first = new Node(1); 
    Node* second = new Node(2);
    Node* third = new Node(3);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;
    print( head);
    del_ele( &head,3);
    print(head);
    return 0;
}