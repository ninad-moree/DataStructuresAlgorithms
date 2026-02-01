/*
    Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.

    Example 1:
    Input: s = "aab"
    Output: 1
    Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int solve(int i, string& s, vector<int>& dp) {
        if(i == s.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;

        for(int j=i; j<s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                int cost = 1 + solve(j+1, s, dp);
                mini = min(mini, cost);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(0, s, dp) - 1;
    }
};