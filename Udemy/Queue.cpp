#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Queue
{
private:
    int length;
    Node *first;
    Node *last;

public:
    Queue(int value)
    {
        Node *newNode = new Node(value);
        first = last = newNode;
        length = 1;
    }

    void printQueue()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getFirst()
    {
        cout << "First: " << first->value << endl;
    }

    void getLast()
    {
        cout << "Last: " << last->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int dequeue()
    {
        if (length == 0)
            return INT_MIN;
        Node *temp = first;
        int result = temp->value;
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = temp->next;
            delete temp;
        }
        length--;
        return result;
    }
};

int main()
{
    Queue *myQueue = new Queue(5);
    myQueue->enqueue(10);
    cout <<"Dequeued value: "<< myQueue->dequeue() << endl;
    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    myQueue->printQueue();
}