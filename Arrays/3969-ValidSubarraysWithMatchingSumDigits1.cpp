/*
    You are given an integer array nums and an integer digit x. A subarray nums[l..r] is considered valid if the sum of its elements satisfies both of the following conditions:
    The first digit of the sum is equal to x. The last digit of the sum is equal to x. Return the number of valid subarrays.

    Example 1:
    Input: nums = [1,100,1], x = 1
    Output: 4
    Explanation: The valid subarrays are: nums[0..0]: sum = 1, nums[0..1]: sum = 1 + 100 = 101, nums[1..2]: sum = 100 + 1 = 101, nums[2..2]: sum = 1. Thus, the answer is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(long long sum, int x) {
        int last = sum % 10;

        if(last != x) 
            return false;

        int first = 0;
        while(sum > 0){
            first = sum % 10;
            sum /= 10;
        }

        return first == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i=1; i<n; i++) 
            prefix[i] = prefix[i-1] + nums[i];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                long long sum = prefix[j];

                if(i > 0)
                    sum -= prefix[i-1];

                if(check(sum, x))
                    ans++;
            }
        }

        return ans;
    }
};