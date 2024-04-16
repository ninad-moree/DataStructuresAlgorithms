/*
    Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
    A pair (i, j) is fair if: 0 <= i < j < n, and lower <= nums[i] + nums[j] <= upper

    Example 1:
    Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
    Output: 6
    Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;
        long long cnt = 0;

        while(i < j) {
            if(nums[i] + nums[j] > upper)
                j--;
            else if(nums[i] + nums[j] < lower)
                i++;
            else if (nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper) {
                int k = i+1;

                while(k<=j) {
                    if(nums[k] + nums[i] >= lower)
                        break;
                    else
                        k++;
                }

                cnt += (j-k+1);
                i++;
            }
        }

        return cnt;
    }
};