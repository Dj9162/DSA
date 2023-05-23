// C++ program to reverse a sentence using stack
#include <iostream>
#include <stack>
using namespace std;
void reverse( string s)
{
    stack <string> st;                          // Defining stack of type string
    for (size_t i = 0; i < s.length(); i++)
    {
        string word = "";
        while ( s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);                          // Pushing each word to stack one by one
        
    }
    while ( !st.empty())                     // Printing stack
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    string str;
    getline(cin,str);
    reverse(str);
    return 0;
}