#include <iostream>
using namespace std;

class CQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    CQueue(int size)
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
        // Overflow
        if ((rear + 1) % size == front)
        {
            cout << "Overflow" << endl;
            return;
        }
        // Empty
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // Circular Case
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // Normal Case
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // Underflow
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        // Single Element
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        // Circular Cae
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // Normal Case
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
};

int main()
{
    CQueue q(5);
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
    q.push(60);

    q.pop();
    q.pop();
    q.pop();
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.print();
    q.push(100);
    q.print();
    q.push(110);
    q.print();
    q.push(120);
    q.print();
    q.push(130);
    q.print();
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    return 0;
}