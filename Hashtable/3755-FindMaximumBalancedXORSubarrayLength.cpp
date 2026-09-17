/*
    Given an integer array nums, return the length of the longest subarray that has a bitwise XOR of zero and contains an equal number of even and odd numbers. If no such 
    subarray exists, return 0.

    Example 1:
    Input: nums = [3,1,3,2,0]
    Output: 4
    Explanation: The subarray [1, 3, 2, 0] has bitwise XOR 1 XOR 3 XOR 2 XOR 0 = 0 and contains 2 even and 2 odd numbers.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        map<pair<int, int>, int> mp; // {xor, diff} -> idx

        int xr = 0;
        int odd = 0;
        int even = 0;
        int ans = 0;

        mp[{0, 0}] = -1;

        for(int i=0; i<n; i++) {
            xr ^= nums[i];

            if(nums[i] % 2 == 0)
                even++;
            else
                odd++;

            int diff = even - odd;

            pair<int, int> key = {xr, diff};

            if(mp.find(key) != mp.end()) 
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }
};