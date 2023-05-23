#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node( int a){ data = a;}
};

void start_Ins( Node** head, int x)
{
    Node* new_node = new Node(x);
    new_node->prev = NULL;
    new_node->next = *head;
    if( (*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
    
}

void add_after( Node* prev_node, int x)
{
    if( prev_node == NULL)
    {
        cout << "Previous node cannot be NULL!" << endl;
        return;
    }
    Node* new_node = new Node(x);
    new_node->prev = prev_node;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    if( new_node->next != NULL)
        new_node->next->prev = new_node;
    
}

void add_end( Node** head, int x)
{
    Node* new_node = new Node(x);
    Node* last = *head;
    new_node->next = NULL;
    if( *head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    while ( last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

void add_before( Node** head, Node* suc, int x)
{
    if( suc == NULL)
    {
        cout << " Given next node cannot be NULL" << endl;
        return;
    }
    Node* new_node = new Node(x);
    new_node->next = suc;
    new_node->prev = suc->prev;
    suc->prev = new_node;
    if( new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head) = new_node;
    
}

void Print( Node* head)
{
    Node* last;
    cout << "Traversal in forward direction:" << endl;
    while ( head != NULL)
    {
        cout << head->data << " ";
        last = head;
        head = head->next;
    }
    cout << endl;
    cout << " Traversal in backward direction:" << endl;
    while (last !=NULL)
    {
        cout << last->data << " ";
        last = last->prev;
    }  
}

int main()
{
    Node* head = NULL;
    start_Ins(&head,15);
    Print(head);
    start_Ins(&head,10);
    Print(head);
    add_end(&head,85);
    Print(head);
    add_end(&head,105);
    Print(head);
    add_after(head->next,75);
    Print(head);
    add_before(&head,head->next,25);
    Print(head);
    return 0;
}