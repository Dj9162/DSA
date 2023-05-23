#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int a){ data = a;}
};

void push( Node** head,int x)
{
    Node* new_node = new Node(x);
    new_node->prev = NULL;
    new_node->next = *head;
    if( (*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}

void delete_Node( Node** head, Node* del)
{
    if(*head == NULL)
        return;
    if( *head == del)
        *head = del->next;
    if( del->prev != NULL)
        del->prev->next = del->next;

    if( del->next != NULL)
        del->next->prev = del->prev;
    free(del);
    return;

}

void Print( Node* head)
{
    while ( head != NULL)
    {
        cout << head->data << " ";
        head = head->next; 
    }
    cout << endl;
    
}
int main()
{
    Node* head = NULL;
    push(&head,5);
    push(&head,25);
    push(&head,15);
    push(&head,45);
    push(&head,35);
    Print(head);
    delete_Node(&head,head);
    Print(head);
    delete_Node(&head,head->next->next);
    Print(head);

    return 0;
}