/*
    You are given a 0-indexed 2D array variables where variables[i] = [ai, bi, ci, mi], and an integer target.
    An index i is good if the following formula holds:
    0 <= i < variables.length
    ((aibi % 10)ci) % mi == target
    Return an array consisting of good indices in any order.

    Example 1:
    Input: variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
    Output: [0,2]
    Explanation: For each index i in the variables array:
    1) For the index 0, variables[0] = [2,3,3,10], (23 % 10)3 % 10 = 2.
    2) For the index 1, variables[1] = [3,3,3,1], (33 % 10)3 % 1 = 0.
    3) For the index 2, variables[2] = [6,1,1,4], (61 % 10)1 % 4 = 2.
    Therefore we return [0,2] as the answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;

        for(int i=0;i<variables.size();i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            long long abi_mod_10 = 1;
            for (int j = 0; j < b; ++j) 
                abi_mod_10 = (abi_mod_10 * a) % 10;

            // Calculate ((ai^bi % 10)^ci) % mi
            long long result_value = 1;
            for (int j = 0; j < c; ++j) 
                result_value = (result_value * abi_mod_10) % m;

            // Check the condition ((ai^bi % 10)^ci) % mi == target
            if (result_value == target) 
                ans.push_back(i);
        }

        return ans;
    }
};