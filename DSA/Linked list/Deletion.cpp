// C++ program to delete an element from a linked list
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void delete_element( Node** n, int key)                       // Function to delete an element from a linked list
{
    Node* temp = *n;                                        // Making new node and store value of head in that
    Node* prev = NULL;                                      // Making new node and store NULL in that

    if ( temp !=NULL && temp->data == key)                  // Checking if first element is equal to required element or not
    {
        *n = temp->next;                                   // If equal then shift head to next element
        delete temp;                                       // Delete the required element
        return;
    }
    else                                                 // If not equal to first element of list
    {
        while ( temp !=NULL && temp->data !=key)         // Loop to check required element is present in list or not
        {
            prev = temp;
            temp = temp->next;
        }

        if( temp == NULL)                               // If required element is not found then from above loop value of temp will be NULL
            cout << "Did not Found!" << endl;
        
        prev->next = temp->next;                        // If required element is found then shift the linkage of previous element from required element to next element

        delete temp;                                    // Deleting the required element
        
    }
    
    
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
    delete_element(&head,3);
    print(head);
    return 0;
}