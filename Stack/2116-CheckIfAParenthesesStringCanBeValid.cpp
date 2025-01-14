/*
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
        It is (). 
        It can be written as AB (A concatenated with B), where A and B are valid parentheses strings. 
        It can be written as (A), where A is a valid parentheses string.
    You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For 
    each index i of locked,
    If locked[i] is '1', you cannot change s[i]. But if locked[i] is '0', you can change s[i] to either '(' or ')'. Return true if you can make s a
    valid parentheses string. Otherwise, return false.

    Example 1:
    Input: s = "))()))", locked = "010100"
    Output: true
    Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
    We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 == 1)
            return false;

        stack<int> open;
        stack<int> unlock;

        for(int i=0; i<s.size(); i++) {
            if(locked[i] == '0')
                unlock.push(i);
            else if(s[i] == '(')
                open.push(i);
            else if(s[i] == ')') {
                if(!open.empty())
                    open.pop();
                else if(!unlock.empty())
                    unlock.pop();
                else
                    return false;
            }
        }

        while(!open.empty() && !unlock.empty()) {
            if(open.top() < unlock.top()) {
                open.pop();
                unlock.pop();
            } else
                break;
        }

        return open.empty();
    }
};