#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
void Insert( Node** head, Node* new_node)
{
    Node* current = *head;
    if( *head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }

    else if( current->data > new_node->data)
    {
        while ( current->next != *head)
            current = current->next;
        current->next = new_node;
        new_node->next = *head;
        *head = new_node;
        
    }

    else
    {
        while ( current->next != *head && current->next->data <= new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
        
    }
    
}
void push( Node** n, int x)
{
    Node* new_node = new Node();
    Node* temp = *n;
    new_node->data = x;
    new_node->next = *n;
    if( *n != NULL)
    {
        while ( temp->next != *n)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        
    }
    else
        new_node->next = new_node;
    *n = new_node;
}
void Print( Node* n)
{
    Node* temp = n;
    if( n != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while( temp != n);
        cout << endl;
    }
}
int main()
{
    Node* head = NULL;
    Node* new_node = new Node();
    new_node->data = 30;
    push(&head,55);
    push(&head,45);
    push(&head,35);
    push(&head,25);
    push(&head,15);
    push(&head,5);
    Print(head);
    Insert( &head, new_node);
    Print(head);
    return 0;
}