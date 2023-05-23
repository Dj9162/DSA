#include <iostream>
using namespace std;
int main()
{
    string str = "abdjgandhadj";
    int freq[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] - 'a']++;                                     //  str[i] - 'a' means ascii value of ith element minus ascii value of 'a'
    }
    int max = 0;
    char alp = 'a';
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            alp = i + 'a';
        }
    }

    cout << max << " " << alp << endl;

    return 0;
}