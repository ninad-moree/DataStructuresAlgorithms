/*
    You are given an integer array nums. In one operation, you can choose any two distinct indices i and j and swap nums[i] and nums[j]. Return an integer denoting the minimum 
    number of operations required to move all 0s to the end of the array.

    Example 1:
    Input: nums = [0,1,0,3,12]
    Output: 2
    Explanation: We perform the following swap operations: Swap nums[0] and nums[3], giving nums = [3, 1, 0, 0, 12]. Swap nums[2] and nums[4], giving nums = [3, 1, 12, 0, 0].
    Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = n-1;

        while(i < j) {
            if(nums[j] == 0)
                j--;
            else if(nums[i] != 0)
                i++;
            else {
                swap(nums[i], nums[j]);
                i++;
                j--;
                ans++;
            }
        }

        return ans;
    }
};