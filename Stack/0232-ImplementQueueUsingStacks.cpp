/*
    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions 
    of a normal queue (push, peek, pop, and empty).
    Implement the MyQueue class:
    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.
    
    Example 1:
    Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 1, 1, false]
*/

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    
    void push(int x) {
        while (!s1.empty()) {
            int y = s1.top();
            s1.pop();
            s2.push(y);
        }

        s1.push(x);

        while (!s2.empty()) {
            int y = s2.top();
            s2.pop();
            s1.push(y);
        }
    }

    int pop() {
        if (s1.empty()) 
            return -1;
        int y = s1.top();
        s1.pop();
        return y;
    }

    int peek() {
        if (s1.empty()) 
            return -1;
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};