#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    public:
        Stack(){
            top = -1;
            size = 100;
            arr = new int[size];

        }
    void push(int x){
        top++;
        arr[top] = x;
    }

    int pop(){
        int x = arr[top];
        top--;
        return x;
    }

    int top(){
        return arr[top];
    }
    int size(){
        return top + 1;
    }
};