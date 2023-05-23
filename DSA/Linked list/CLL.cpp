#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

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

void split_list( Node* head, Node** head1, Node** head2 )
{
    Node* fast = head;
    Node* slow = head;
    if( head == NULL)
        return;
    
    while ( fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if( fast->next->next == head)
        fast = fast->next;
    
    *head1 = head;
    if( head->next != head)
        *head2 = slow->next;
    
    fast->next = slow->next;
    slow->next = head;
    
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
    Node* head1 = NULL;
    Node* head2 = NULL;
    push(&head,55);
    push(&head,45);
    push(&head,35);
    push(&head,25);
    push(&head,15);
    push(&head,5);
    Print(head);
    split_list( head, &head1,&head2);
    Print( head1);
    Print( head2);
    return 0;
}