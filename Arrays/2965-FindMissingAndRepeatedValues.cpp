/*
    You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
    Each integer appears exactly once except a which appears twice and b which is missing. The task is 
    to find the repeating and missing numbers a and b.
    Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

    Example 1:
    Input: grid = [[1,3],[2,2]]
    Output: [2,4]
    Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n*n;

        vector<int> freq(m, 0);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int ele = grid[i][j];
                freq[ele-1]++;
            }
        }
        
        int rep = 0, miss = 0;

        for(int i=0;i<m;i++) {
            if(freq[i]==2)
                rep = i+1;
            if(freq[i]==0)
                miss = i+1;
        }

        return {rep, miss};
    }
};