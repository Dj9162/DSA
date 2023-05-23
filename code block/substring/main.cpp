#include <iostream>
using namespace std;
void sub_str(string s,string ans)
{
    if(s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch= s[0];
    string sub = s.substr(1);
    sub_str(sub,ans);
    sub_str(sub,ans+ch);
}
int main()
{
    sub_str("ABC","");
    cout << endl;
    return 0;
}
