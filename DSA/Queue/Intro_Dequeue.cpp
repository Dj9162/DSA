#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque <int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    for(auto i : dq)
        cout << i << " ";
    cout << "\n";
    dq.pop_front();
    dq.pop_back();
    for(auto i : dq)
        cout << i << " ";

    return 0;
}