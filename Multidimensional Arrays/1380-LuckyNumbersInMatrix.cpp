/*
    Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
    A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

    Example 1:
    Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    Output: [15]
    Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;

        vector<int> mini;
        set<int> maxi;

        for(int i=0; i<matrix.size(); i++) {
            int miniEle = INT_MAX;
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] < miniEle) 
                    miniEle = matrix[i][j];
            }
            mini.push_back(miniEle);
        }

        for(int i=0; i<matrix[0].size(); i++) {
            int maxiEle = INT_MIN;
            for(int j=0; j<matrix.size(); j++) {
                if(matrix[j][i] > maxiEle) 
                    maxiEle = matrix[j][i];
            }
            maxi.insert(maxiEle);
        }

        for(int i=0; i<mini.size(); i++) {
            if(maxi.find(mini[i]) != maxi.end())
                ans.push_back(mini[i]);
        }

        return ans;
    }
};