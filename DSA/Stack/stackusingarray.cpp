/* Stack is a data structure which follow a particular order in which the operations are performed. The order may be LIFO or FILO*/
#include <iostream>
#define MAX 100
using namespace std;
class Stack
{
    int top;       // Used as index of array
    int* arr;      // array is dynamically defined
    public:
        Stack()              // contructor to allocate array dynamically and setting value of top as -1
        {
            arr = new int[MAX]; 
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x)                               // Function to add a element to the stack
{
    if( top == MAX - 1)                         // Checking if the stack(array) is full or not
    {
        cout << " Stack Overflow!!" << endl;    // When the stack is full and we push(add) another element then that is called stack overflow
        return false;
    }
    else                           // If stack is not full then add the given element in the array
    {
        arr[++top] = x;
        cout << x << " is pushed into the stack" << endl;
        return true;
    }
    
}

int Stack::pop()         // Function to remove an element from the stack
{
    if(top == -1)                // If the stack is empty and we remove an element from that then this case is called stack underflow
    {
        cout << " Stack Underflow!!" << endl;
        return 0;
    }
    else // If stack is not empty then remove upper element
    {
        int x = arr[--top];
        return x;
    }
    
}

int Stack::peek()           // Function to print the uppermost element of stack
{
    if(top == -1)                // Checking if stack is empty or not
    {
        cout << "Stack is empty!!" << endl;
        return -1;
    }
    return arr[top];   // returning upper element from the stack
}

bool Stack::isEmpty()         //Function to check if stack is empty or not
{
    return( top == -1);  // If top(index) is -1 then stack is empty else it is not empty
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.peek() << endl;
    cout << s.pop() << " Popped from stack\n";
    cout << "Elements present in stack: ";
    while (!s.isEmpty())                       // To print elements of stack
    {
        cout << s.peek() << " ";  // printing upper element
        s.pop();// removing upper element
    }
    

    return 0;
}