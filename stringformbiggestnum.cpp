#include <iostream>
#include<string>
#include <algorithm>
using namespace std;
int main()
{
    string num = "45739";
    for (int i = 0; i < num.size()-1; i++)                          // Used here to sort each letter of string
    {
        for (int j = i+1; j < num.size(); j++)
        {
            if (num[j] > num[i])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }   
        }   
    }
    
    cout << num << endl;

    sort(num.begin(),num.end(), greater<int>());                  // Used to sort in descending  order            
    cout << num << endl;
    
    sort(num.begin(),num.end());                                  // Used to sort in ascending order
    cout << num << endl;

    return 0;
}