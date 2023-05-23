// C++ program to Insert elements in a linkes list
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void start_Ins(Node** n , int data)     // Function to insert element at the start
{
    Node* new_node = new Node();            // Allocating/ Making new node of name new_node
    new_node->data =  data;                // Storing data
    new_node->next = *n;                  // Make next of new_node to head
    *n = new_node;                       // Moving head to point to the new_node
}

void Insertafter(Node* prev, int data)         // Function to insert an element after a given element
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev->next;              // Making new_node->next to refer that element which previous elements used to refer
    prev->next = new_node;                    // Making previous elements next to refer new_node element
}

void End_Ins(Node** n,int data)               // Function to insert an element at the end of the list
{
    Node* new_node = new Node();
    Node* last = *n;                          // storing address of n means first element in new node name last
    new_node->data = data;
    new_node->next = NULL;                    // Since the new_node is last element so making its next as NULL
    if (*n == NULL)                           // If the list is empty then add element at the start and make it head
    {
        *n = new_node;
        return;
    }
    
    while (last->next !=NULL)                 // storing last element's address to last using while loop
        last = last->next;

    last->next = new_node;                    // making last element to refer new_node
    return;
}

void print(Node* n)
{
    while (n !=NULL)
    {
        cout << n->data << "->";
        n=n->next;
    }
    cout << "NULL" << endl;   
}
int main()
{
    Node* head = new Node();
    Node* first  = new Node();
    Node* second= new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    head->data = 0;head->next = first;
    first->data = 1;first->next = second;
    second->data = 2;second->next = third;
    third->data = 3;third->next = fourth;
    fourth->data = 4 ;fourth->next = NULL;
    print(head);
    start_Ins(&head,-1);
    print(head);
    Insertafter(second, 10);
    print(head);
    End_Ins(&head,5);
    print(head);

    return 0;
}