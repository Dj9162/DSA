// C++ program to delete an element from linked list using recursion
#include <iostream>
using namespace std;
// Initializing Node using structure
struct Node{
    int info;
    Node* link = NULL;
   
    Node (int a)
        : info(a){}
};

void delete_node(Node*& n, int val)                   // Function to delete node
{
    if( n == NULL)                                    // If element is not found in the list then
    {
        cout << "Element not found!" << endl;
        return;
    }
    if ( n->info == val)                            // checking if element is equal to the required value
    {
        Node* temp = n;                            // store that element in new temp node
        n = n->link;                               // shifting the link of previous element to the next element of the required element
        delete temp;                              // deleting the required element
        return;
    }
    delete_node( n->link,val);                     // calling same function again passing next element as argument
}

void push( Node*& n, int data)               // adding element to the start
{
    Node* new_node = new Node(data);
    new_node->link = n;
    n = new_node;
}

void print(Node* n)                          // print using recursion
{
    if(n == NULL && cout << endl)             // If we reached at last element or not
        return;
    cout << n->info << " ";
    print(n->link);

}

int main()
{
    Node* head = NULL;
    push(head, 10);
    push(head, 12);
    push(head, 14);
    push(head, 15);
    print(head);
    delete_node(head,12);
    print(head);
    delete_node(head,20);
    print(head);
    return 0;
}