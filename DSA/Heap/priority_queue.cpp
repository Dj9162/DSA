// c++ program to implement min heap and max heap using priority queue
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>> pq;  // To use max heap we pass an integer and a container in priority queue
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout << pq.top() << endl; // it always give max element
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout <<pq.top() << endl;

    priority_queue<int,vector<int>,greater<int>> pqm; // To use min heap we pass an integer, a container and a greater to convert max heap into min heap
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    cout << pqm.top() << endl; // it always give min element
    pqm.pop();
    cout << pqm.top() << endl;
    return 0;
}