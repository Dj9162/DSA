// C++ program to print all permutation of a string
#include <iostream>
using namespace std;
void Per_str(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        Per_str(ros,ans+ch);
    }
    
}
int main()
{
    Per_str("ABC","");
    return 0;
}