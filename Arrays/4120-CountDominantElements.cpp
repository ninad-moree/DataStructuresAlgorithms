/*
    You are given an integer array nums. An element in nums is called dominant if it is greater than or equal to the average of its immediate neighbors.
    The immediate neighbors of nums[i] are nums[i - 1] and nums[i + 1], when those indices exist. A single element with no neighbors is considered dominant.
    Return the number of dominant elements in nums.

    Example 1:
    Input: nums = [1,10,2]
    Output: 1
    Explanation: For nums[0] = 1, its only neighbor is 10. Since 1 < 10, it is not dominant. For nums[1] = 10, its neighbors are 1 and 2. Their average is (1 + 2) / 2 = 1.5. 
    Since 10 > 1.5, it is dominant. For nums[2] = 2, its only neighbor is 10. Since 2 < 10, it is not dominant. Therefore, the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        if(nums.size() == 1)
            return 1;

        if(nums[0] >= nums[1])
            ans++;

        for(int i=1; i<nums.size()-1; i++) {
            int num = nums[i];
            int prev = nums[i-1];
            int next = nums[i+1];
            double avg = (prev + next) / 2.0;

            if(num >= avg)
                ans++;
        }

        if(nums[n-1] >= nums[n-2])
            ans++;

        return ans;
    }
};