#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *kNode = head;
    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }
    Node *prev = kNode->back;
    Node *front = kNode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHead(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}

// Function to insert a new node with value 'k' at the end of the doubly linked list
Node *insertAtTail(Node *head, int k)
{
    // Create a new node with data 'k'
    Node *newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr)
    {
        return newNode;
    }

    // Traverse to the end of the doubly linked list
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // Connect the new node to the last node in the list
    tail->next = newNode;
    newNode->back = tail;

    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2DLL(arr);
    return 0;
}