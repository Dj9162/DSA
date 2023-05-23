#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int a)
        : data(a){}
};

int length( Node* head)
{
    int n = 0;
    Node* current = head;
    while ( current != NULL)
    {
        n++;
        current = current->next;
    }
    return n;
    
}
int length_list( Node* n)
{
    if ( n == NULL)
    {
        return 0;
    }
    return 1 + length_list(n->next);
}
int main()
{
    Node* head = new Node(0);
    Node* first = new Node(1); 
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    cout << length(head) << endl;
    cout << length_list(head) << endl;
    return 0;
}