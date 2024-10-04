#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(100);
    pq.push(90);
    pq.push(70);

    cout << "Top element of heap: " << pq.top() << endl;
    pq.pop();
    cout << "Top element of heap: " << pq.top() << endl;
    return 0;
}