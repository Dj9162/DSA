#include <iostream>
using namespace std;

class twoStack
{
    int* arr;
    int size;
    int top1,top2;
    public:
        twoStack(int n)
        {
            size = n;
            arr = new int[n];
            top1 = n/2 + 1;
            top2 = n/2;
        }
        void push1(int x)
        {
            if(top1 > 0)
            {
                top1--;
                arr[top1] = x;
            }
            else
            {
                cout << "Stack1 Overflow! By element :"<< x << endl;
                return;
            }
            
        }
        void push2(int x)
        {
            if( top2 < size - 1)
            {
                top2++;
                arr[top2] = x;
            }
            else
            {
                cout <<"Stack2 Overflow!!" << "By element : " << x << endl;
                return;
            }
            
        }
        int pop1()
        {
            if( top1 <=size/2)
            {
                int x = arr[top1];
                top1++;
                return x;
            }
            else
            {
                cout << "Stack Underflow!!" << endl;
                exit(1);
            }
            
        }
        int pop2()
        {
            if( top2 >= size/2 + 1)
            {
                int x = arr[ top2];
                top2--;
                return x;
            }
            else
            {
                cout << "Stack Underflow!!" << endl;
                exit(1);
            }
            
        }
};
int main()
{
    twoStack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(20);
    ts.push2(11);
    cout << "Popped element from stack1 is" << ":" << ts.pop1() << endl;
    ts.push2(40);
    cout << "\n Popped element from stack2 is" << ":" << ts.pop2() << endl;
    return 0;
}