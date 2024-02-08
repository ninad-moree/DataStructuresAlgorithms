/*
    Given an integer n, return the least number of perfect square numbers that sum to n.
    A perfect square is an integer that is the square of an integer; in other words, it is 
    the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

    Example 1:
    Input: n = 12
    Output: 3
    Explanation: 12 = 4 + 4 + 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) 
            return 0;

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) 
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }

        return dp[n];
    }
};