/*
    You are given a string s of length n consisting of lowercase English letters. You must perform exactly one operation by choosing any integer k such that 1 <= k <= n & either:
    reverse the first k characters of s, or reverse the last k characters of s. Return the lexicographically smallest string that can be obtained after exactly one such 
    operation.

    Example 1:
    Input: s = "dcab"
    Output: "acdb"
    Explanation: Choose k = 3, reverse the first 3 characters. Reverse "dca" to "acd", resulting string s = "acdb", which is the lexicographically smallest string achievable.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reversePortion(string& s, int l, int r) {
        reverse(s.begin() + l, s.begin() + r + 1);
    }

    string lexSmallest(string s) {
        string ans = s;

        for(int i=0; i<s.size(); i++) {
            string rev = s;
            reversePortion(rev, 0, i);

            ans = min(ans, rev);

            rev = s;
            reversePortion(rev, i+1, rev.size() - 1);

            ans = min(ans, rev);
        }

        return ans;
    }
};