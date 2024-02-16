/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    Implement the MinStack class:
    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

    Example 1:
    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]
*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {}

    stack<int> st;

    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp = st;
        int mini = INT_MAX;
        while(!temp.empty()) {
            int top = temp.top();
            if(mini > top)
                mini = top;
            temp.pop();
        }
        return mini;
    }
};
