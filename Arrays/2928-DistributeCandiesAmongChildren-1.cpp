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
    int distributeCandies(int n, int limit) {
        int ans = 0;

        for (int i = 0; i <= limit; ++i) {
            for (int j = 0; j <= limit; ++j) {
                for (int k = 0; k <= limit; ++k) {
                    if (i + j + k == n && i <= limit && j <= limit && k <= limit) 
                        ans++;
                }
            }
        }
        
        return ans;
    }
};