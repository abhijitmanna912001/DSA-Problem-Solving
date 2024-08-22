#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void createTail(Node *head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position < 1)
    {
        cout << "Cannot insert" << endl;
    }

    int length = getLength(head);
    if (position == 1)
    {
        insertAtHead(head, data);
    }
    else if (position == length + 1)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        // middle of linked list
        Node *newNode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Deletion not possible";
        return;
    }

    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int len = getLength(head);
    // delete from head
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    // delete from tail
    else if (position == len)
    {
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    // delete from middle
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    createTail(head, tail);
    insertAtTail(head, tail, 50);
    printLL(head);
    deleteNode(head, tail, 1);
    printLL(head);
    return 0;
}