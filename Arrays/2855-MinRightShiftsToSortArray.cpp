/*
    You are given a 0-indexed array nums of length n containing distinct positive integers. 
    Return the minimum number of right shifts required to sort nums and -1 if this is not possible.
    A right shift is defined as shifting the element at index i to index (i + 1) % n, for all indices.

    Example 1:
    Input: nums = [3,4,5,1,2]
    Output: 2
    Explanation: 
    After the first right shift, nums = [2,3,4,5,1].
    After the second right shift, nums = [1,2,3,4,5].
    Now nums is sorted; therefore the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());

        int firstEle = nums[0];
        int cnt = 0;

        if(copy == nums)
            return cnt;

        while(nums.back() != firstEle) {
            int lastElement = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), lastElement);

            cnt++;

            if(copy == nums)
                return cnt;
        }

        return -1;
    }
}; 