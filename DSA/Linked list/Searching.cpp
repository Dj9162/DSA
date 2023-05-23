// C++ program to search the element in linked list
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int a)
        : data(a){}
};

bool search( Node* n, int key )
{
    while ( n != NULL)
    {
        if( n->data == key)
            return true;
        n = n->next;
    }
    return false;
    
}

void search_element( Node* n, int key)     // Using recursion
{
    if( n == NULL)
    {
        cout << "NOT FOUND !!" << endl;
        return;
    }
    if( n->data == key)
    {
        cout << "TRUE" << endl;
        return;
    }
    search_element( n->next,key);
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
    cout << search( head, 14) << endl;
    search_element( head, 4);
    return 0;
}