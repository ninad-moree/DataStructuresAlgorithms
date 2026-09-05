/*
    You are given an integer array nums. An index i is balanced if the sum of elements strictly to the left of i equals the product of elements strictly to the right of i.
    If there are no elements to the left, the sum is considered as 0. Similarly, if there are no elements to the right, the product is considered as 1. Return an integer 
    denoting the smallest balanced index. If no balanced index exists, return -1.

    Example 1:
    Input: nums = [2,1,2]
    Output: 1
    Explanation: For index i = 1: Left sum = nums[0] = 2, Right product = nums[2] = 2. Since the left sum equals the right product, index 1 is balanced.
    No smaller index satisfies the condition, so the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> sum(n);
        vector<long long> prod(n);

        sum[0] = 0;
        prod[n-1] = 1;

        for(int i=1; i<n; i++) 
            sum[i] = sum[i-1] + nums[i-1];

        for (int i = n - 2; i >= 0; i--) {
            if (prod[i + 1] > LLONG_MAX / nums[i + 1]) 
                prod[i] = LLONG_MAX;
            else 
                prod[i] = prod[i + 1] * nums[i + 1];
        }

        int idx = -1;

        for(int i=0; i<n; i++) {
            if(sum[i] == prod[i]) {
                idx = i;
                break;
            }
        }
        
        return idx;
    }
};