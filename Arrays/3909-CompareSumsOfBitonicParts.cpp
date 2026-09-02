/*
    You are given a bitonic array nums of length n. Split the array into two parts: Ascending part: from index 0 to the peak element (inclusive).
    Descending part: from the peak element to index n - 1 (inclusive). The peak element belongs to both parts. Return:
    0 if the sum of the ascending part is greater. 1 if the sum of the descending part is greater. -1 if both sums are equal.

    Example 1:
    Input: nums = [1,3,2,1]
    Output: 1
    Explanation: Peak element is nums[1] = 3 Ascending part = [1, 3], sum is 1 + 3 = 4. Descending part = [3, 2, 1], sum is 3 + 2 + 1 = 6 Since the descending part has a larger sum, return 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int peakIdx = -1;
        long long sum = 0;

        for(int i=0; i<nums.size(); i++) {
            int pI = i-1;
            int nI = i+1;
            sum += nums[i];

            if(pI >= 0 && nI < nums.size()) {
                if(nums[i] > nums[pI] && nums[i] > nums[nI]) 
                    peakIdx = i;
            }
        }

        long long ascSum = 0;
        for(int i=0; i<=peakIdx; i++)
            ascSum += nums[i];

        long long descSum = sum - ascSum + nums[peakIdx];

        if(ascSum == descSum)
            return -1;
        else if(ascSum > descSum)
            return 0;
        return 1;
    }
};