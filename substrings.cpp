// C++ program to print all the substrings of a string
/*                                  ""
                        A                      ""
                AB              A        B              ""
            ABC     AB       AC    A  BC    B      C           ""
*/
#include <iostream>
using namespace std;
void sub_str(string s,string ans)
{
    if(s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch= s[0];                            // To store first letter of string
    string sub = s.substr(1);
    sub_str(sub,ans);                        // One time don't add anything 
    sub_str(sub,ans+ch);                     // Abother time add ch
}
int main()
{
    sub_str("ABC","");                       // ans is initialized by ""
    cout << endl;
    return 0;
}