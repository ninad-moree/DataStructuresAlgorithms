/*
    Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so
    that the resultant expression evaluates to the target value. Note that operands in the returned expressions should not contain leading zeros.
    Note that a number can contain multiple digits.

    Example 1:
    Input: num = "123", target = 6
    Output: ["1*2*3","1+2+3"]
    Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string num, int target, int idx, long long val, long long lastOperand, string res, vector<string>& ans) {
        if(idx == num.size()) {
            if(val == target)
                ans.push_back(res);
            return;
        }

        for(int i=idx; i<num.size(); i++) {
            if(i > idx && num[idx] == '0')
                return;

            string curr = num.substr(idx, i - idx + 1);
            long long currVal = stoll(curr);

            if(idx == 0)
                solve(num, target, i+1, currVal, currVal, curr, ans);
            else {
                solve(num, target, i+1, val + currVal, currVal, res + "+" + curr, ans); // +
                solve(num, target, i+1, val - currVal, -currVal, res + "-" + curr, ans); // -
                solve(num, target, i+1, val - lastOperand + lastOperand * currVal, lastOperand * currVal, res + "*" + curr, ans); // *
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        solve(num, target,0, 0, 0, "", ans);

        return ans;
    }
};