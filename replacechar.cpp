/* Replacing pi in a string to 3.14 using recursion*/
#include <iostream>
using namespace std;
void rep_char(string s)
{
    if (s.length() ==0)              // If we get length of string  0 then simply return the function
    {
        return;
    }
    
    if (s[0]=='p' && s[1]=='i')     // Check if first and second character of string is pi then replace that with 3.14 and pass new string in function with removing first two character
    {
        cout << "3.14";
        rep_char(s.substr(2));
    }
    else                           // If first two character is not pi then simply print first character and pass new string with removing 1 character from string in the function
    {
        cout<< s[0];
        rep_char(s.substr(1));
    }
    
}
int main()
{
    string str = "pixlsjppiiflspxipi";
    rep_char(str); 
    return 0;
}