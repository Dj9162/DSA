// Program to remove to duplicate character from a string : "aaabbbcccrree"
#include <iostream>
using namespace std;
string rem_dup(string s)
{
    if ( s.length() == 0)
    {
        return "";
    }
    char ch = s[0];                                // To store first character of each substring 
    string rem = rem_dup(s.substr(1));            // calling same function for length-1 string
    if ( ch == rem[0])                           // if first character of previous string is same as first character of next string
    {
        return rem;                            // returning only next string 
    }
    return (ch+rem);                         // returning both character and string
}
int main()
{
    string str= "aaabbbbeeeccdd";
    cout << rem_dup(str);
    return 0;
}