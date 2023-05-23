#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};

void cycle(Node* head){

    Node* slow = head, *fast = head;

    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
}


int main(){
    Node* head = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = first;
    cycle(head);

    return 0;
}
