#include <iostream>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    queue<int> second;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = q.front();
        q.pop();
        second.push(temp);
    }
    for (int i = 0; i < size / 2; i++)
    {
        int temp = second.front();
        second.pop();
        q.push(temp);
        temp = q.front();
        q.pop();
        q.push(temp);
    }

    // For GFG Problem
    // vector<int> result;
    // while (!q.empty())
    // {
    //     result.push_back(q.front());
    //     q.pop();
    // }

    // return result;
}

int main()
{

    return 0;
}