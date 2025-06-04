/*
    Given a string s which represents an expression, evaluate this expression and return its value. The integer division should truncate toward zero.
    You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
    Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

    Example 1:
    Input: s = "3+2*2"
    Output: 7
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char op = '+'; 
        int num = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            char c = s[i];

            if (isdigit(c)) 
                num = num * 10 + (c - '0');

            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') 
                    stk.push(num);
                else if (op == '-') 
                    stk.push(-num);
                else if (op == '*') {
                    int prev = stk.top(); 
                    stk.pop();
                    cout<<prev<<endl;
                    stk.push(prev * num);
                } else if (op == '/') {
                    int prev = stk.top(); 
                    stk.pop();
                    stk.push(prev / num); 
                }

                op = c;
                num = 0;
            }
        }

        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};