/*
    Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
    You may return the answer in any order.

    Input: s = "cbaebabacd", p = "abc"
    Output: [0,6]
    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        
        if (n < m) 
            return ans;

        vector<int> p_freq(26, 0), s_freq(26, 0);

        for (char ch : p) 
            p_freq[ch - 'a']++;

        for (int i = 0; i < m; i++) 
            s_freq[s[i] - 'a']++;
        
        if (p_freq == s_freq) 
            ans.push_back(0);

        for (int i = m; i < n; i++) {
            s_freq[s[i - m] - 'a']--; 
            s_freq[s[i] - 'a']++;    

            if (p_freq == s_freq) 
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};