/*
    You may recall that an array arr is a mountain array if and only if: arr.length >= 3
    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
    Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

    Example 1:
    Input: arr = [2,1,4,7,3,2,5]
    Output: 5
    Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        if(n < 3)
            return 0;

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        for(int i=1; i<n; i++) {
            if(arr[i-1] < arr[i])
                dp1[i] = 1 + dp1[i-1];
        }

        for(int i=n-2; i>=0; i--) {
            if(arr[i+1] < arr[i])
                dp2[i] = 1 + dp2[i+1];
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(dp1[i] > 0 && dp2[i] > 0)
                ans = max(ans, dp1[i] + dp2[i] + 1);
        }
        
        return ans;
    }
};