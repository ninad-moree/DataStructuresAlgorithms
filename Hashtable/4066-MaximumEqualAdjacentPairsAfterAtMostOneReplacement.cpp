/*
    You are given a 1-indexed integer array nums. You can choose two distinct values x and y and perform the following operation at most once: Replace every occurrence of x in 
    nums with y. Return the maximum possible number of pairs of adjacent elements that are equal after performing the operation.

    Example 1:
    Input: nums = [1,2,3,2]
    Output: 2
    Explanation: One optimal solution is to choose x = 3 and y = 2. The resulting array is [1, 2, 2, 2]. There are 2 pairs of adjacent elements that are equal: (nums[2], 
    nums[3]) and (nums[3], nums[4]). Therefore, the answer is 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> mp;

        int pairs = 0;
        int alreadyEqual = 0;

        for(int i=1; i<nums.size(); i++) {
            int mini = min(nums[i-1], nums[i]);
            int maxi = max(nums[i-1], nums[i]);

            mp[{mini, maxi}]++;

            if(nums[i-1] == nums[i])
                alreadyEqual++;
            else
                pairs = max(pairs, mp[{mini, maxi}]);
        }

        return pairs + alreadyEqual;
    }
};