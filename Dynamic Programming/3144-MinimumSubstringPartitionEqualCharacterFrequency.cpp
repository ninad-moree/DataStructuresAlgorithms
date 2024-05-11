/*
    Given a string s, you need to partition it into one or more balanced  substrings 
    For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), 
    ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.
    Return the minimum number of substrings that you can partition s into.
    Note: A balanced string is a string where each character in the string occurs the same number of times.

    Example 1:
    Input: s = "fabccddg"
    Output: 3
    Explanation:
    We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1002];
        
    int solve(int newIdx, string& newStr) {
        if(newIdx < 0)
            return 0;
        if(dp[newIdx] != -1)
            return dp[newIdx];
        
        int freq[26] = {0};
        int minStr = 5005;
        
        for(int i=newIdx; i>=0; i--) {
            freq[newStr[i] - 'a'] ++;
            int maxFreq = -1;
            int minFreq = 5005;
            
            for(int j=0; j<26; j++) {
                if(freq[j]) {
                    minFreq = min(minFreq, freq[j]);
                    maxFreq = max(maxFreq, freq[j]);
                }
            }
            
            if(minFreq == maxFreq)
                minStr = min(minStr, 1 + solve(i-1, newStr));
        }
        
        return dp[newIdx] = minStr;
        
    }
    
    int minimumSubstringsInPartition(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s.size()-1, s);
    }
};