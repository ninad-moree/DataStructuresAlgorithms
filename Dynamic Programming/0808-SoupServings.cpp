/*
    You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 
    independent of all previous turns: pour 100 mL from type A and 0 mL from type B, pour 75 mL from type A and 25 mL from type B, pour 50 mL from type A and 50 mL from type B
    pour 25 mL from type A and 75 mL from type B
    Note:
    There is no operation that pours 0 mL from A and 100 mL from B. The amounts from A and B are poured simultaneously during the turn. If an operation asks you to pour more 
    than you have left of a soup, pour all that remains of that soup. The process stops immediately after any turn in which one of the soups is used up. Return the probability 
    that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.

    Example 1:
    Input: n = 50
    Output: 0.62500
    Explanation:  If we perform either of the first two serving operations, soup A will become empty first. If we perform the third operation, A and B will become empty at the 
    same time. If we perform the fourth operation, B will become empty first. So the total probability of A becoming empty first plus half the probability that A and B become 
    empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double solve(int a, int b, vector<vector<double>>& dp) {
        if(a <= 0 && b <= 0)
            return 0.5;
        if(b <= 0) 
            return 0;
        if(a <= 0) 
            return 1;

        if(dp[a][b] != -1)
            return dp[a][b];

        double c1 = solve(a - 100, b, dp);
        double c2 = solve(a - 75, b - 25, dp);
        double c3 = solve(a - 50, b - 50, dp);
        double c4 = solve(a - 25, b - 75, dp);

        return dp[a][b] = 0.25 * (c1 + c2 + c3 + c4);
    }

    double soupServings(int n) {
        if(n > 4800)
            return 1;

        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));

        return solve(n, n, dp);
    }
};