/*
    You are given an integer array nums. The digit range of an integer is defined as the difference between its largest digit and smallest digit. For example, the digit range 
    of 5724 is 7 - 2 = 5. Return the sum of all integers in nums whose digit range is equal to the maximum digit range among all integers in the array.

    Example 1:
    Input: nums = [5724,111,350]
    Output: 6074
    Explanation: The maximum digit range is 5. The integers with this digit range are 5724 and 350, so the answer is 5724 + 350 = 6074.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitRange(int num) {
        string s = to_string(num);
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto i : s) {
            int n = i - '0';
            mini = min(mini, n);
            maxi = max(maxi, n);
        }

        return maxi - mini;
    }

    int maxDigitRange(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        vector<int> range(nums.size());

        for(int i=0; i<nums.size(); i++) {
            int r = digitRange(nums[i]);
            maxi = max(maxi, r);
            range[i] = r;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(range[i] == maxi) 
                sum += nums[i];
        }

        return sum;
    }
};