/*
    A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros. For example, 
    "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. Given a string s containing only 
    digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the 
    valid IP addresses in any order.

    Example 1:
    Input: s = "25525511135"
    Output: ["255.255.11.135","255.255.111.35"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& s, int start, int length) {
        return length == 1 ||  (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
    }

    void solve(int idx, string s, vector<string>& ans, string res, int parts) {
        if(parts == 4) {
            if(idx == s.size()) {
                res.pop_back(); // last "."
                ans.push_back(res);
            }

            return;
        }

        for(int len=1; len<=3; len++) {
            if(idx + len > s.size())
                break;

            if(!isValid(s, idx, len))
                continue;

            string part = s.substr(idx, len);

            solve(idx + len, s, ans, res + part + ".", parts + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(0, s, ans, "", 0);

        return ans;
    }
};