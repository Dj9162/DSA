#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter total number of places in array " << endl;
    cin >> n;
    int visitors[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of places" << endl;
        cin >> visitors[i];
    }
    int mx = visitors[0];
    int i = 0;
    cout << "Breakrecorder days are: " << endl;
    while (i + 1 < n)
    {
        if (visitors[i] > mx && visitors[i] > visitors[i + 1])
        {
            cout << " " << visitors[i];
            mx = max(mx, visitors[i]);
        }
        i++;
    }
    return 0;
}
