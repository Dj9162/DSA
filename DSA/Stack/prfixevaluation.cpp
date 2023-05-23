//C++ program to evaluate prefix operation here operator comes before operand
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prfix_Eval( string s)
{
    stack <int> st;
    for (int i = s.length() - 1; i >=0; i--)
    {
        if( s[i] >= '0' && s[i] <= '9')  // If we get number then we push them into the stack
            st.push(s[i] - '0');
        else                            // If we get operator then we pop two numbers from the stack and store them into two variable and do operations and then push it into the stack
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                cout << "Invalid operator" << endl;
                break;
            }
        }
        
    }

    return st.top();             // At last we return top value of stack means evaluated value of given expression
}
int main()
{
    cout << prfix_Eval("+^423") << endl;
    return 0;
}