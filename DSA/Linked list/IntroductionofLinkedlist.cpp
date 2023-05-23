#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;              // Variable to store data of each linked list
        Node* next;            // pointer to store address of next linked list and connect the whole linked list
};

void printList(Node* n){          // Function to print the linked list
    // Here n denotes the head i.e; first pointer of linked list
    while (n!=NULL)                   // Iterate loop untill n becomes NULL i.e; at the end of list
    {
        cout << n->data << "-->";
        n = n->next;
    }
    cout << "NULL" << endl;
    
}
int main()
{
    // Allocate 3 nodes in the heap to use dynamic space
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    // Three blocks have been allocated dynamically. We have pointers to these three blocks as head, second and third
    head = new Node();
    second = new Node();
    third = new Node();
    //Data is random because we haven't assigned anything yet
    head->data = 1;                // assign data in first node
    head->next = second;           // Link first node with second node

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;           // Link third node with NULL to terminate the chain of linked list
    
    printList(head);              // NOte tht only the head is sufficient to represent the whole list.
                                  // We can traverse the complete list by following the next pointers.
    return 0;
}