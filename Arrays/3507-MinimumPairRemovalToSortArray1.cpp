/*
    Given an array nums, you can perform the following operation any number of times: Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose 
    the leftmost one. Replace the pair with their sum. Return the minimum number of operations needed to make the array non-decreasing. An array is said to be non-decreasing if 
    each element is greater than or equal to its previous element (if it exists).

    Example 1:
    Input: nums = [5,2,3,1]
    Output: 2
    Explanation:
    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    The array nums became non-decreasing in two operations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while(nums.size() > 1) {
            bool isAsc = true;
            int minSum = INT_MAX;
            int idx = -1;

            for(int i=0; i<nums.size()-1; i++) {
                int sum = nums[i] + nums[i+1];

                if(nums[i] > nums[i+1])
                    isAsc = false;

                if(sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            if(isAsc)
                break;

            ans++;
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1); 
        }

        return ans;
    }
};