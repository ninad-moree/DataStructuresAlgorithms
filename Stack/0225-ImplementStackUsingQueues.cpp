/*
    Implement a last-in-first-out (LIFO) stack using only two queues. 
    The implemented stack should support all the functions of a normal 
    stack (push, top, pop, and empty).
    Implement the MyStack class:
    void push(int x) Pushes element x to the top of the stack.
    int pop() Removes the element on the top of the stack and returns it.
    int top() Returns the element on the top of the stack.
    boolean empty() Returns true if the stack is empty, false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> mainQueue;
    queue<int> tempQueue;
public:
    MyStack() {}
    
    void push(int x) {
        while (!mainQueue.empty()) {
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        mainQueue.push(x);

        while (!tempQueue.empty()) {
            mainQueue.push(tempQueue.front());
            tempQueue.pop();
        }
    }
    
    int pop() {
        int topElement = mainQueue.front();
        mainQueue.pop();
        return topElement;
    }
    
    int top() {
        return mainQueue.front();
    }
    
    bool empty() {
        return mainQueue.empty();
    }
};

