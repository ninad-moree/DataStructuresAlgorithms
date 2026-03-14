/*
    A happy string is a string that:
    consists only of letters of the set ['a', 'b', 'c']. s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed). For example, strings "abc", "ac", "b"
    and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings. Given two integers n and k, consider a list of all happy strings of length
    n sorted in lexicographical order. Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

    Example 1:
    Input: n = 1, k = 3
    Output: "c"
    Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, string curr, vector<string>& strs) {
        if(curr.size() == n) {
            strs.push_back(curr);
            return;
        }

        for(char c='a'; c<='c'; c++) {
            if(curr.size() > 0 && curr.back() == c)
                continue;
            
            solve(n, curr + c, strs);
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> happy;

        solve(n, curr, happy);

        if(happy.size() < k)
            return "";
        return happy[k-1];
    }
};