/*
    You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:
        m is greater than 1.
        s1 = s0 + 1.
    The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.
    Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [2,3,4,3,4]
    Output: 4
    Explanation: The alternating subarrays are [3,4], [3,4,3], and [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size()-1 ;i++) {
            int len = 1;
            bool flag = true;
            for(int j=i+1; j<nums.size(); j++) {
                if(flag && nums[j]-nums[j-1] == 1) {
                    len++;
                    ans = max(ans, len);
                } else if(!flag && nums[j]-nums[j-1] == -1) {
                    len++;
                    ans = max(ans, len);
                } else
                    break;
                flag = !flag;
            }
        }

        if(ans==0) return -1;
        return ans;
    }
};