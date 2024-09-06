#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushFront(int val)
    {
        if (front == 0)
        {
            cout << "Overflow" << endl;
            return;
        }
        // Empty Deque
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val)
    {
        // OverFlow Case
        if (rear == size - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        // Empty Deque
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // Normal Case
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void popFront()
    {
        // Underflow
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
            return;
        }

        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};

int main()
{
    // deque<int> dq;
    // dq.push_back(10);
    // dq.push_front(20);
    // // dq.pop_back();
    // dq.pop_front();
    // cout << dq.front() << endl;
    // cout << dq.back() << endl;
    // cout << dq.size() << endl;
    return 0;
}