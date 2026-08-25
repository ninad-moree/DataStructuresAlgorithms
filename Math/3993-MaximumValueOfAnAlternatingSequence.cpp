/*
    You are given three integers n, s, and m.  sequence seq of integers of length n is considered valid if: seq[0] = s.
    The sequence is alternating, meaning that either: seq[0] > seq[1] < seq[2] > ..., or seq[0] < seq[1] > seq[2] < ....
    For every adjacent pair, |seq[i] - seq[i - 1]| <= m. A sequence of length 1 is considered alternating. 
    Return the maximum possible element that can appear in any valid sequence.

    Example 1:
    Input: n = 4, s = 3, m = 5
    Output: 12
    Explanation: One valid sequence is [3, 8, 7, 12]. The maximum element in the sequence is 12.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1)
            return s;

        long long seq = s;
        long long M = m;

        // seq[0] < seq[1] > seq[2]
        long long seqA = (long long)n / 2;
        long long caseA = seq + seqA * (m-1) + 1;
        
        // seq[0] > seq[1] < seq[2]
        long long seqB = ((long long)n - 1) / 2;
        long long caseB = seq + seqB * (m-1);

        return max(caseA, caseB);
        
        /* TLE Code */
        // long long seq = s;
        // long long ans = s;
        // long long len = 1;

        // if(n == 1)
        //     return seq;

        // // seq[0] < seq[1] > seq[2]
        // bool great = true;
        // while(len != n) {
        //     long long prev = seq;
        //     if(great) 
        //         seq = prev + m;
        //     else
        //         seq = prev - 1;
            
        //     ans = max(ans, seq);
        //     great = !great;
        //     len++;
        // }

        // // seq[0] > seq[1] < seq[2]
        // great = false;
        // while(len != n) {
        //     long long prev = seq;
        //     if(great) 
        //         seq = prev + m;
        //     else
        //         seq = prev - 1;
            
        //     ans = max(ans, seq);
        //     great = !great;
        //     len++;
        // }

        // return ans;
    }
};