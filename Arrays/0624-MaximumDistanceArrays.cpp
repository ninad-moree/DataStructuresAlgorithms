/*
    You are given m arrays, where each array is sorted in ascending order. You can pick up two integers from two different arrays (each array 
    picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
    Return the maximum distance.

    Example 1:
    Input: arrays = [[1,2,3],[4,5],[1,2,3]]
    Output: 4
    Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int sm = arrays[0][0];
        int big = arrays[0].back();
        int maxi = 0;

        for(int i=1; i<arrays.size(); i++) {
            maxi = max(maxi, abs(arrays[i].back() - sm));
            maxi = max(maxi, abs(arrays[i][0] - big));

            sm = min(sm, arrays[i][0]);
            big = max(big, arrays[i].back());
        }

        return maxi;
    }
};