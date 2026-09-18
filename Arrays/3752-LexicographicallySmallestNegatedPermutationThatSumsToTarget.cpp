/*
    You are given a positive integer n and an integer target. Return the lexicographically smallest array of integers of size n such that: The sum of its elements equals target.
    The absolute values of its elements form a permutation of size n. If no such array exists, return an empty array. A permutation of size n is a rearrangement of integers 
    1, 2, ..., n.

    Example 1:
    Input: n = 3, target = 0
    Output: [-3,1,2]
    Explanation: The arrays that sum to 0 and whose absolute values form a permutation of size 3 are:
    [-3, 1, 2], [-3, 2, 1], [-2, -1, 3], [-2, 3, -1], [-1, -2, 3], [-1, 3, -2], [1, -3, 2], [1, 2, -3], [2, -3, 1], [2, 1, -3], [3, -2, -1], [3, -1, -2]
    The lexicographically smallest one is [-3, 1, 2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sum(long long x) {
        return x * (x + 1) / 2;
    }

    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long s = sum(n);

        if(target < -s || target > s)
            return {};

        vector<int> ans;

        for(int i=n; i>=1; i--) {
            // negative
            if(sum(i-1) - i >= target) {
                target += i;
                ans.push_back(-i);
            } else {
                target -= i;
                ans.push_back(i);
            }
        }

        if(target != 0)
            return {};

        sort(ans.begin(), ans.end());

        return ans;
    }
};