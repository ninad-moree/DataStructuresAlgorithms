/*
    You are given an integer n. The score of n is defined as the sum of d * freq(d) over all distinct digits d, where freq(d) denotes the number of times the digit d appears in
    n. Return an integer denoting the score of n.

    Example 1:
    Input: n = 122
    Output: 5
    Explanation: The digit 1 appears 1 time, contributing 1 * 1 = 1. The digit 2 appears 2 times, contributing 2 * 2 = 4. Thus, the score of n is 1 + 4 = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mp;

        while(n) {
            int d = n % 10;
            n = n/10;

            mp[d]++;
        }

        int ans = 0;

        for(auto i : mp) {
            int d = i.first;
            int f = i.second;

            ans += (d * f);
        }

        return ans;
    }
};