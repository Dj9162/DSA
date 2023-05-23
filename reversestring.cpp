/* Program to print reverse of a string, Using recursion*/
#include <iostream>
#include <string>
using namespace std;
void rev_str(string s)
{
    if (s.length() == 0)        // base case: when string reached to its last place i.e; its length becomes 0 then it simply return
        return;
    
    string rev = s.substr(1);    // New string to store substring of given string every time one less digit from starting
    rev_str(rev);                // calling same function for new string
    cout << s[0];              // Printing first letter of all new strings created till now, it will be reversed 
}
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin,str);
    rev_str(str);
    return 0;
}