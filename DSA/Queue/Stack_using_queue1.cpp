#include <bits/stdc++.h>
using namespace std;
class Stack{
    int N;
    queue <int> q1;
    queue <int> q2;
    public:
    Stack(){ N = 0;}

    void push(int x)
    {
        q1.push(x);
        N++;
    }
    void pop()
    {
        if(q1.empty())
            return;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue <int> temp = q1;
        q1 = q2;
        q2 = temp;
        
    }

    int size()
    { return N;}

    int top()
    {
        if(q1.empty())
            return -1;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q2.push(temp);
        queue <int> temp1 = q1;
        q1 = q2;
        q2 = temp1;
        return temp;
        
    }

};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
   
    cout << s.size() << endl;
    return 0;
}