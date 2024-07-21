/*
    You are given two positive integers n and k. You can choose any bit in the binary representation of n that is equal to 1 and 
    change it to 0. Return the number of changes needed to make n equal to k. If it is impossible, return -1.

    Example 1:
    Input: n = 13, k = 4
    Output: 2
    Explanation:
    Initially, the binary representations of n and k are n = (1101)2 and k = (0100)2.
    We can change the first and fourth bits of n. The resulting integer is n = (0100)2 = k.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        if (k > n) 
            return -1;
        
        int ans = 0;

        while (n > 0 || k > 0) {
            int nBit = n & 1;
            int kBit = k & 1;

            if (nBit == 0 && kBit == 1) 
                return -1;
            else if (nBit == 1 && kBit == 0)
                ans++;
            
            n >>= 1;
            k >>= 1;
        }

        return ans;
    }
};