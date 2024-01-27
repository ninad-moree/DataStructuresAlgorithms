/*
    You are given two positive integers n and limit.
    Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

    Example 1:
    Input: n = 5, limit = 2
    Output: 3
    Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: 
    (1, 2, 2), (2, 1, 2) and (2, 2, 1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int i=0;i<=limit;i++) {
            ans += max(min(limit, n-i) - max(0, n-i-limit) + 1, 0);
        }

        return ans;
    }
};