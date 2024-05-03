#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue()
    {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == maxSize)
        {
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currSize++;
    }

    int pop()
    {
        if (start == -1)
        {
            return
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
    }
}