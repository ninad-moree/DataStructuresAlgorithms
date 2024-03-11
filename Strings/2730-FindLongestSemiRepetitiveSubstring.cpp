/*
    You are given a 0-indexed string s that consists of digits from 0 to 9.
    A string t is called a semi-repetitive if there is at most one consecutive pair of the same digits inside t. 
    For example, 0010, 002020, 0123, 2002, and 54944 are semi-repetitive while 00101022, and 1101234883 are not.
    Return the length of the longest semi-repetitive substring inside s.
    A substring is a contiguous non-empty sequence of characters within a string.

    Example 1:
    Input: s = "52233"
    Output: 4
    Explanation: The longest semi-repetitive substring is "5223", which starts at i = 0 and ends at j = 3. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1;

        for(int i=0; i<s.size(); i++) {
            int freq = 0;

            for(int j=i+1; j<s.size(); j++) {
                if(s[j-1] == s[j])
                    freq++;
                
                if(freq <= 1)
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};