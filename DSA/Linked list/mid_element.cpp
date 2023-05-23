// C++ program to find and print the mid element of list
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int a)
        : data(a){}
};

int mid_ele( Node* n)
{
    int count = 0;
    Node* temp = n, *tem_p = n;
    while ( temp != NULL)                    // To find total length of linked list
    {
        count++;
        temp = temp->next;
    }
    for(int i = 0; i < ((count/2)); i++)   // To traverse the list to mid 
        tem_p = tem_p->next;
    return tem_p->data;                    // To print mid data of list
    
}

class NodeOperation{                    // New class
    public:
    void mid( class Node* n)        // Function to print mid element using two node fast and slow
    {
        struct Node* fast_ptr = n;
        struct Node* slow_ptr = n;
        if ( n != NULL)
        {
            while ( fast_ptr != NULL && fast_ptr->next != NULL) // If fast node reaches to end of list then slow node will reach at middle of list
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            
            cout << "The middle element is " << slow_ptr->data << endl;
        }
    }
};

void print_mid( Node* n)            // Function to print mid element of list
{
    int count = 0;
    Node* mid = n;
    while ( n != NULL)
    {
        if( count & 1)             // To increase mid node to next node if count is odd
            mid = mid->next;
        ++count;
        n = n->next;
    }
    if( mid != NULL)
        cout << "The middle element is " << mid->data << endl;
    
}

int main()
{
    class NodeOperation *temp = new NodeOperation();
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
    cout << mid_ele( head) << endl;
    temp->mid(head);
    print_mid( head);

    return 0;
}