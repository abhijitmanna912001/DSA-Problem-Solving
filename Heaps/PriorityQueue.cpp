#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "Top element of heap: " << pq.top() << endl;
    pq.pop();
    cout << "Top element of heap: " << pq.top() << endl;
    cout << "Size of max heap: " << pq.size() << endl;
    return 0;
}