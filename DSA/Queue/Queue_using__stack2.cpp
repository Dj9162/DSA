#include <bits/stdc++.h>
using namespace std;
class Queue{
    stack <int> s;
    public:
    void push(int x)
    {
        s.push(x);
    }
    int pop()
    {
        if(s.empty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        int x = s.top();
        s.pop();
        if(s.empty())
            return x;
        int item = pop();
        s.push(x);
        return item;
    }
    bool empty()
    {
        if(s.empty())
            return true;
        return false;
    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;

    return 0;
}