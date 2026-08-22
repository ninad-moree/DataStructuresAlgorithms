/*
    You are given a binary string s. A prefix of s is considered valid if its characters can be rearranged to form an alternating string. Return the number of valid prefixes of
    s. A string is considered alternating if no two adjacent characters are equal.
    
    Example 1:
    Input: s = "00101"
    Output: 3
    Explanation: The valid prefixes are: "0": It is already an alternating string. "001": It can be rearranged into "010", which is an alternating string.
    "00101": It can be rearranged into "01010", which is an alternating string. Thus, the answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0')
                cnt0++;
            if(s[i] == '1')
                cnt1++;

            if(abs(cnt0 - cnt1) <= 1)
                ans++;
        }   

        return ans;
    }
};