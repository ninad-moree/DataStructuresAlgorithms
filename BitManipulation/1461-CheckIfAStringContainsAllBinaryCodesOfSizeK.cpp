/*
    Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

    Example 1:
    Input: s = "00110110", k = 2
    Output: true
    Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if ((1 << k) > n - k + 1)
            return false;
        
        unordered_set<string> st;
        
        for (int i = 0; i <= n - k; i++) 
            st.insert(s.substr(i, k));
        
        return st.size() == (1 << k);
    }
};