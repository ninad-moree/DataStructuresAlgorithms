/*
    Given two strings s and t of lengths m and n respectively, return the minimum window 
    substring of s such that every character in t (including duplicates) is included in the 
    window. If there is no such substring, return the empty string "".
    The testcases will be generated such that the answer is unique.

    Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int miniLen = INT_MAX;
        int sIdx = -1;
        vector<int> hash(256, 0);

        for(int i=0; i<t.size(); i++)
            hash[t[i]]++;

        while(r < s.size()) {
            if(hash[s[r]] > 0) 
                cnt++;
            hash[s[r]]--;

            while(cnt == t.size()) {
                int currLen = r - l + 1;
                if(currLen < miniLen) {
                    miniLen = currLen;
                    sIdx = l;
                }
                
                hash[s[l]]++;
                if(hash[s[l]] > 0)
                    cnt--;
                
                l++;
            }

            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, miniLen);
    }
};