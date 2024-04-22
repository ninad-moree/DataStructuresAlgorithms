/*
    You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
    The chosen integers have to be in the range [1, n]. Each integer can be chosen at most once. The chosen integers should not be in the array 
    banned. The sum of the chosen integers should not exceed maxSum.
    Return the maximum number of integers you can choose following the mentioned rules.

    Example 1:
    Input: banned = [1,6,5], n = 5, maxSum = 6
    Output: 2
    Explanation: You can choose the integers 2 and 4.
    2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mp;
        for(auto i : banned)
            mp[i]++;
        
        int cnt = 0;
        int curr = 0;

        for(int i=1; i<=n; i++) {
            if(curr + i <= maxSum && mp.find(i) == mp.end()) {
                curr = curr+i;
                cnt++;
            }
        }

        return cnt;
    }
};