// C++ program to swap two element of linked list
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int a)
        : data(a){}
};
void swap( Node** n, int x, int y)
{
    if( x == y) // If both element is equal then there is no need to swap elements
        return;
    
    Node* prevX = NULL, *currentX = *n;
    while ( currentX && currentX->data != x)    // To get prev and current node of first given element
    {
        prevX = currentX;
        currentX = currentX->next;
    }

    Node *prevY = NULL, *currentY = *n;
    while (currentY && currentY->data != y)     // To get prev and current node of second given element
    {
        prevY = currentY;
        currentY = currentY->next;
    }

    if( currentX == NULL || currentY == NULL)   // If both current node is equal to NULL then there is no such element
    {
        cout << " Element not Found!" << endl;
        return;
    }

    if( prevX != NULL)               // If prevX node is not equal to NULL
        prevX->next = currentY;     // Then set prevX->next to currentY 
    else
        *n = currentY;     // If prevX node is equal to NULL then first element will be head
    if( prevY != NULL)
        prevY->next = currentX;
    else
        *n = currentX;
    
    Node* temp = currentX->next;          // Now change the next of both current to one another
    currentX->next = currentY->next;
    currentY->next = temp;

}

void swa_p ( Node*&a, Node*&b)         // Function to swap two nodes
{
    Node* temp = a;
    a = b;
    b = temp;
}

void swap_ele( Node** n, int x, int y)
{
    if( x == y )
        return;
    
    Node **a = NULL, **b = NULL;
    while ( *n)                    // To find both required node in a single loop
    {
        if( (*n)->data == x)
            a = n;
        else if ( (*n)->data == y)
            b = n;
        
        n = &((*n)->next);
    }

    if ( a && b)             // Now swap address of both elements to each other and next of both to each other
    {
        swa_p( *a, *b);
        swa_p(((*a)->next), ((*b)->next));
    }
    
}
 
void print( Node *n)
{
    if( n == NULL)
        return;
    cout << n->data << " ";
    print( n->next);
}
int main()
{
    Node* head = new Node(0);
    Node* first = new Node(1); 
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* five = new Node(5);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = five;
    five->next = NULL;
    print(head);
    swap( &head, 2, 3);
    cout << endl;
    print(head);
    // swap_ele( &head, 1, 5);
    // cout << endl;
    // print(head);
    
    return 0;
}