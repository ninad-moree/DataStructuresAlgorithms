/*
    You are given a binary string s. A string is considered coherent if it does not contain "011" or "110" as subsequences. In one operation, you can flip any character in s 
    ('0' to '1' or '1' to '0'). Return an integer denoting the minimum number of operations required to make s coherent.

    Example 1:
    Input: s = "1010"
    Output: 1
    Explanation: Flip s[0] to get "0010", which contains no "011" or "110" subsequences.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int cnt1 = 0;

        for(auto i : s) {
            if(i == '1')
                cnt1++;
        }

        int cnt0 = n - cnt1;

        if(cnt1 <= 1 || cnt0 == 0)
            return 0;

        int removeZero = cnt0; // string contains only 1's
        int one1 = max(cnt1 - 1, 0); // string contains only one 1's
        int boundary1 = cnt1 - (s[0] - '0') - (s[n-1] - '0'); // keep boundary 1's and remove rest all ones

        return min({removeZero, one1, boundary1});
    }
};