/*
    You are given a binary string s and an integer k. A binary string satisfies the k-constraint if either of the following conditions holds:
    The number of 0's in the string is at most k. The number of 1's in the string is at most k.
    Return an integer denoting the number of substrings of s that satisfy the k-constraint.

    Example 1:
    Input: s = "10101", k = 1
    Output: 12
    Explanation: Every substring of s except the substrings "1010", "10101", and "0101" satisfies the k-constraint.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            int zero = 0;
            int one = 0;
            for(int j = i; j < s.size(); j++) { 
                if(s[j] == '1')
                    one++;
                if(s[j] == '0')
                    zero++;

                if(one <= k || zero <= k)
                    ans++;
                else
                    break; 
            }
        }

        return ans;
    }
};