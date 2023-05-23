// C++ program to reverse a stack without using extra stack
#include <iostream>
#include <stack>
using namespace std;
void insertatbottom( stack <int> &st, int ele)    // Function to insert elements at the bottom of the stack
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();              // storing top element of stack
    st.pop();
    insertatbottom(st,ele);            // calling function recursively
    st.push(topele);
}

void reverse_stack( stack <int> &st)       // Function to reverse  stack
{
    if( st.empty())
        return;
    int ele = st.top();  // To store top element of stack in ele
    st.pop();
    reverse_stack(st);   // calling reverse function recursively
    insertatbottom( st,ele);  // calling function to insert elements at bottom of the stack
}

int main()
{
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse_stack(st);
    while (!st.empty())
    {
        cout << st.top() << " " ;
        st.pop();
    }
    
    return 0;
}