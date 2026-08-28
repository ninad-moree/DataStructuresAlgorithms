/*
    You are given two integers n and k. The cost of a binary string s is defined as the sum of all indices i (0-based) such that s[i] == '1'. A binary string is considered 
    valid if: It does not contain two consecutive '1' characters. Its cost is less than or equal to k. Return a list of all valid binary strings of length n in any order.

    Example 1:
    Input: n = 3, k = 1
    Output: ["000","010","100"]
    Explanation: The binary strings of length 3 without consecutive '1' characters are:
    "000" : cost = 0, "100" : cost = 0, "010" : cost = 1, "001" : cost = 2, "101" : cost = 0 + 2 = 2
    Among these, the strings with cost less than or equal to k = 1 are "000", "010" and "100". Thus, the valid strings are ["000", "010", "100"].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int k, char prev, string& res, vector<string>& ans, int cost, int idx) {
        if(res.size() == n && cost <= k) {
            ans.push_back(res);
            return;
        }

        if(res.size() > n)
            return;
        
        if(cost > k)
            return;

        if(prev == '\0' || prev != '1') {
            solve(n, k, '0', res += '0', ans, cost, idx+1);
            res.pop_back();
            solve(n, k, '1', res += '1', ans, cost + idx, idx+1);
            res.pop_back();
        } else {
            solve(n, k, '0', res += '0', ans, cost, idx+1);
            res.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string res = "";
        char ch = '\0';
        
        solve(n, k, ch, res, ans, 0, 0);

        return ans;
    }
};