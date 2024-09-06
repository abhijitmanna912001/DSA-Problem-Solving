#include <iostream>
#include <queue>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    void push(int val)
    {
        // check full
        if (rear == size - 1)
            return;
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underflow
        if (front == -1 && rear == -1)
            return;
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

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    int getSize()
    {
        if (front == -1 && rear == -1)
            return 0;
        else
            return rear - front + 1;
    }

    int getFront()
    {
        // no element in queue
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    int getRear()
    {
        // no element in queue
        if (rear == -1)
            return -1;
        else
            return arr[rear];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.print();
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    cout << q.getSize() << endl;
    q.pop();
    q.print();
    cout << q.getSize() << endl;
    q.push(100);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.pop();
    q.print();
    cout << q.getSize() << endl;
    return 0;
}