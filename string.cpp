/* All the functions of string*/
#include <iostream>
#include <string>                                        // To use all the string functions
#include <algorithm>                                     // To use sort function
using namespace std;
int main()
{
    // string s;
    // getline(cin,s);                                   // Used to take input the whole line with spaces
    // cout << s << endl;

    string s1 = "Fam" , s2 = "ily";
    // cout << s1.append(s2) << endl;                    // Used to add two strings side by side as written in function from left to rigth. It adds two strings and store that in first string that used
    // cout << s1 + s2 << endl;                          // It also used to add two strings but it does not store added string 

    s1.clear(),s2.clear();                               // Clear all the contents of string

    s1 = "dhanraj", s2 ="agj";
    // cout << s1.compare(s2) << endl;                  // Used to compare two string if they are equal then it gives 0, else if first string lexicography greater than second it gives 1 else gives -1
 
    // if (s1.empty())                                  // Used to check emptyness of string, if string is empty it gives 0 else 1
    // {
    //     cout << "S1 is empty" << endl;
    // }
    // else
    //     cout << "s1 is not empty" << endl;

    // s1.erase(3,2);                                   // Used to erase some contents of string  .erase(start_index, number_of_letters_that_is_removed)
    // cout << s1 << endl;
    
    // cout << s1.find("raj") <<endl;                   // Used to find a word in string and gives index of first letter of that word

    // s1.insert(3,"ok");                               // Used to insert word in string .insert( index , word )
    // cout << s1 << endl;

    // cout << s1.size() << endl;                       // Used to determine the length of string
    // cout << s1.length() << endl;

    // string s = s1.substr(4,6);                       // Used to print small word from string .substr( start_index , end_index )
    // cout << s << endl;

    // string s = "786";
    // int x = stoi(s);                                 // Used to convert string to integer
    // cout << x+2 << endl;

    // int x = 786;
    // string s = to_string(x);                         // Used to convert integer to string
    // cout << s + '2' << endl;

    // sort(s1.begin(), s1.end());                      // Used to sort the string
    // cout << s1 << endl;

    return 0;
}