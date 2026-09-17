/*
    You are given an array of integers arr and an integer target. You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple 
    answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum. Return the minimum sum of the lengths of the two required sub-arrays, 
    or return -1 if you cannot find such two sub-arrays.

    Example 1:
    Input: arr = [3,2,2,4,3], target = 3
    Output: 2
    Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int len = n + 1;

        // dp[idx] = valid subarray len ending before idx
        vector<int> dp(n + 1, n);

        while(j < arr.size()) {
            sum += arr[j];

            while(sum > target) {
                sum -= arr[i];
                i++;
            }

            dp[j + 1] = dp[j];

            if(sum == target) {
                int currLen = j - i + 1;
                len = min(len, currLen + dp[i]);

                dp[j + 1] = min(dp[j], currLen );
            }

            j++;
        }

        return len == n + 1 ? -1 : len;
    }
};