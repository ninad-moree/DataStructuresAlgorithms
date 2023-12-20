/*
    You are given a string s and an integer k, a k duplicate removal consists 
    of choosing k adjacent and equal letters from s and removing them, causing 
    the left and the right side of the deleted substring to concatenate together.
    We repeatedly make k duplicate removals on s until we no longer can.
    Return the final string after all such duplicate removals have been made. 
    It is guaranteed that the answer is unique.

    Input: s = "deeedbbcccbdaa", k = 3
    Output: "aa"
    Explanation: 
    First delete "eee" and "ccc", get "ddbbbdaa"
    Then delete "bbb", get "dddaa"
    Finally delete "ddd", get "aa"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;

        for (char ch : s) {
            if (stack.empty() || stack.top().first != ch)
                stack.push({ch, 1});
            else {
                stack.top().second++;

                if (stack.top().second == k) 
                    stack.pop(); 
            }
        }

        string result = "";
        while (!stack.empty()) {
            pair<char, int> current = stack.top();
            stack.pop();
            result = string(current.second, current.first) + result; 
        }

        return result;
    }
};