// C++ program to get node if position is given
#include <iostream>
#include <assert.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int a)
        : data(a){}
};

int get_node( Node *n, int x)       // Function to print node if position is given
{
    if( n == NULL)
    {
        cout << " List is Empty!" << endl;
        return 0;
    }
    int count =0;
    Node* current = n;
    while ( current != NULL)
    {
        if( count == x)                     // To find given position
            return (current->data) ;
        count++;
        current = current->next;
    }
    assert(0);
}

int get_Node( Node *n, int x)    // Function to print node if position given using recursion
{

    if( n == NULL)
        return 0;
    if( x == 0)                 // If we find required position
        return n->data;          // print data of that node
    
    return get_Node( n->next, x-1); // passing next node and position - 1
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
    cout << get_node( head, 4) << endl;
    cout << get_Node(head,3);
    return 0;
}