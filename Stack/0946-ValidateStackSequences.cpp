/*
    Given two integer arrays pushed and popped each with distinct values, 
    return true if this could have been the result of a sequence of push 
    and pop operations on an initially empty stack, or false otherwise.

    Example 1:
    Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    Output: true
    Explanation: We might do the following sequence:
    push(1), push(2), push(3), push(4),
    pop() -> 4,
    push(5),
    pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            s.push(pushed[i]); 

            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++; 
            }
        }
        
        return s.empty();
    }
};