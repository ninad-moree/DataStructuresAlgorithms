/*
    You are given a positive integer n. A binary string x is valid if all substrings
    of x of length 2 contain at least one "1". Return all valid strings with length n, in any order.

    Example 1:
    Input: n = 3
    Output: ["010","011","101","110","111"]
    Explanation:
    The valid strings of length 3 are: "010", "011", "101", "110", and "111".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(string s) {
        for (int i = 0; i <s.length()-1; ++i) {
            if (s[i] == '0' && s[i + 1] == '0') 
                return false;
        }
        return true;
    }

    void solve(int n, string s, vector<string>& arr) {
        if (s.size() == n) {
            if (valid(s)) 
                arr.push_back(s);
            return;
        }
        solve(n, s + '0', arr);
        solve(n, s + '1', arr);
    }
    
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};