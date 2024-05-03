#include<bits/stdc++.h>
using namespace std;


class Stack{
    queue<int> q;
    public:
        void push(int x){
            int s = q.size();
            q.push(x);
            for (int i = 0; i < s; i++){
                q.push(q.front());
                q.pop();
            }
        

        }
        int pop(){
            int n = q.front();
            q.pop();
            return n;
        }

        int Top(){
            return q.front();
        }
        int Size(){
            return q.size();
        }
}