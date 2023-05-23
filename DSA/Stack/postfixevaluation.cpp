// C++ program to evaluate postfix expression where operators comes after operand
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prfix_Eval( string s)
{
    stack <int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if( s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else
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

    return st.top();
}
int main()
{
    cout << prfix_Eval("42*3+") << endl;
    return 0;
}