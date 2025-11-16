/*
    Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

    Example 1:
    Input: s = "0110111"
    Output: 9
    Explanation: There are 9 substring in total with only 1's characters.
    "1" -> 5 times. "11" -> 3 times. "111" -> 1 time.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        int ones = 0;
        int i = 0;
        int j = 0;
        long long ans = 0;

        unordered_map<int, int> mp;

        while(i < s.size()) {
            j = i;
            int cnt = 0;
            if(s[i] == '1') {
                while(s[j] == '1') {
                    cnt++; 
                    j++;
                }

                mp[j-1] = cnt;
                i = j;
            } else
                i++;
        }

        for(auto i : mp) {
            long long ones = i.second;
            long long cnt = (ones * (ones + 1) / 2) % MOD;
            ans = (ans + cnt) % MOD;
        }

        return ans;
    }
};