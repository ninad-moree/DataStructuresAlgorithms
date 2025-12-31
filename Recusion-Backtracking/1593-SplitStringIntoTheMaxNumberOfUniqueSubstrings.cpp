/*
    Given a string s, return the maximum number of unique substrings that the given string can be split into. You can split string s into any list of 
    non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of 
    them are unique. A substring is a contiguous sequence of characters within a string.

    Example 1:
    Input: s = "ababccc"
    Output: 5
    Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 
    'a' and 'b' multiple times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string& s, int start, unordered_set<string>& st) {
        if(start == s.size())
            return 0;

        int splits = 0;
        string subString;

        for(int i=start; i<s.size(); i++) {
            subString += s[i];

            if(st.find(subString) == st.end()) {
                st.insert(subString);
                splits = max(splits, 1 + solve(s, i+1, st));
                st.erase(subString);
            }
        }

        return splits;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(s, 0, st);
    }
};