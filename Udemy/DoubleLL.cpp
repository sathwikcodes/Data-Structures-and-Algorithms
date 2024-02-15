#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }
    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }
    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
            length++;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
        {
            return;
        }
        else if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else
        {
            Node *temp = tail;
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
        }

        length--;
    }

    void Prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
            length++;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    void DeleteFirst()
    {
        if (length == 0)
        {
            return;
        }
        else if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
    }

    Node *Get(int index)
    {
        Node *temp = head;
        if (index < 0 || index >= length)
        {
            return nullptr;
        }
        else if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool Set(int index, int value)
    {
        Node *temp = Get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool Insert(int index, int value)
    {
        Node *newNode = new Node(value);
        if (index < 0 || index > length)
        {
            return false;
        }
        else if (index == 0)
        {
            Prepend(value);
        }
        else if (index == length)
        {
            append(value);
        }
        else
        {
            Node *before = Get(index - 1);
            Node *after = before->next;
            newNode->next = after;
            newNode->prev = before;
            before->next = newNode;
            after->prev = newNode;
        }
        length++;
        return true;
    }

    bool DeleteNode(int index)
    {
        if (index < 0 || index > length)
        {
            return false;
        }
        else if (index == 0)
        {
            DeleteFirst();
        }
        else if (index == length)
        {
            deleteLast();
        }
        else
        {
            Node *temp = Get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
        }
        length--;
        return true;
    }
};

int main()
{
    DoublyLinkedList *myDll = new DoublyLinkedList(7);
    myDll->append(1212);
    myDll->Prepend(1143);
    // cout << myDll->Get(1)->value << endl;
    // myDll->DeleteFirst();
    // myDll->deleteLast();
    myDll->DeleteNode(0);
    myDll->Insert(1, 121313);
    myDll->printList();
}